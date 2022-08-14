# So_Long

## COMEÇANDO

---
### Incluindo a miniLibX:

```C
#include “mlx.h”
```

Primeiro, precisamos inicializar o mlx com `mlx_init()`, que retorna um `void *` que precisamos salvar porque muitas das funções da biblioteca precisam disso para funcionar.

```C
void	*mlx_pointer = mlx_init();
```

Então, eu abro a janela com a função `mlx_new_window()` que recebe o `mlx_pointer`, o tamanho da janela e o título que seria exibido no topo. Retornando um `void *` que é uma referência à janela aberta. Novamente, precisamos salvá-lo para uso posterior.

```C
void	*window = mlx_new_window(mlx_pointer, width, height, name);
```

Eu acho realmente útil usar um `struct`, especialmente para ligar funções mais tarde, que contém todos esses dados que seu programa precisaria:

```C
typedef struct	s_program
 {
	void	*mlx_pointer;
	void	*window;
	// … etc
}				t_program;
```

Finalmente, depois de configurar tudo que você precisa para rodar, para iniciar seu programa você precisa chamar a função `mlx_loop()`. Este é um loop infinito que manteria o programa em execução, a janela aberta e continuaria detectando os diferentes eventos e chamando as funções que você ligou a eles. Qualquer código escrito após a chamada para esta função nunca seria executado.

```C
mlx_loop(mlx_pointer);
```

Como o `miniLibX` usa `Appkit` e `MX11`, você precisa vinculá-los adicionando `-lmlx -framework OpenGL -framework AppKit` quando você compila.

---

### Vinculando

A miniLibX permite que você 'vincule' algumas de suas funções a determinados eventos. Então, quando esses eventos acontecem, como pressionar uma tecla, fechar ou focar uma janela, uma função sua é chamada. A maneira mais genérica de fazer isso é com a função `mlx_hook()`, que tem o seguinte protótipo:

```C
mlx_hook(void *win_ptr, int event, int mask, int (*f)(), void *param);
```

Ele recebe respectivamente um ponteiro para a janela que detecta o evento. O código do evento . A mascára. Um ponteiro para a função que seria chamada quando o evento especificado ocorresse e um ponteiro que seria passado para sua função como parâmetro. Isso significa que as funções que você conectou precisam ter um protótipo muito específico que se pareça com isso:

```C
int	hooked_function(void *param);
```

Ele tem que retornar um `int`, mas esse valor nunca é usado para nada que eu saiba. Como você pode ver, ele só pode receber um ponteiro para uma variável, então o que normalmente é feito é passar um ponteiro para uma estrutura que contém todas as informações que sua função precisa para funcionar. O que eu faço é fazer com que essa função receba toda a estrutura do programa para que ela tenha acesso ao `mlx_pointer`, à janela e a qualquer outra coisa que possa precisar.

Aqui você tem uma lista com todos os eventos e máscaras. Eu nunca usei máscaras para nada e realmente não sei como elas funcionam, mas, bem, aí estão elas: https://harm-smits.github.io/42docs/libs/minilibx/events.html

Alguns eventos úteis:

| Code    | Event    |
| ------- | -------- |
| 2  | Key pressed   |
| 3  | Key released  |
| 4  | Mouse pressed |
| 5  | Mouse released|
| 6  | Motion        |
| 17 | Window closed |

Por padrão, quando você fecha a janela, você não para o `mlx_loop`, para que seu programa continue rodando infinitamente. Você precisa ligar uma função que faz `exit(0)`; ao evento de fechamento da janela, para que o programa termine quando a janela for fechada.

Este outro guia tem mais informações sobre o `miniLibX`, e muitos links além da biblioteca mlx, com recursos úteis para os projetos cubo 3D, fdf e fractal. Confira: https://github.com/qst0/ft_libgfx#the-graphics-branch

#### Mais algumas coisas sobre vinculos.

Quando você vincula uma função a um evento relacionado a uma chave, ela precisa ter um protótipo diferente. Recebendo um `int` extra que indica a tecla que foi pressionada ou liberada. Para saber o código de cada tecla basta imprimir este valor e pressionar cada tecla que deseja saber o código.

```C
int	key_hooked_function(int keycode, void *param);
```

There are also more hook functions. The most important and useful is the mlx_loop_hook() that triggers each repetition of the loop. Calling your function each frame. For more on these other hook functions see: https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html#hooks

---

### Imagens

Existem algumas funções que criam e retornam um ponteiro para uma imagem. Que você precisa salvar para desenhar ou manipular essa imagem mais tarde. Essas funções são:

```C
void	*mlx_new_image(void *mlx_ptr, int width, int height);
void	*mlx_xpm_file_to_image(void *mlx_pointer, char *relative_path, int *width, int *height);
```

* ``mlx_new_image``. Cria uma imagem de `width` x ``height`` pixels. Todos eles pretos por padrão.
* ``mlx_xmp_file_to_image``. Cria um que contém a imagem `.xpm` found in ``relative_path`` e salva sua `width` e `height` em pixels para os ponteiros dados. Você só pode usar imagens no formato xpm. Então aqui está o conversor de png para xmp que usei: https://anyconv.com/png-to-xpm-converter/

Para manipular os pixels de uma imagem você primeiro precisa chamar `mlx_get_data_addr()`.

````c
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
````

Isso retornaria um array de char contendo todos pixels da imagem e salvando nos ponteiros passados como parâmetros as informações correspondentes sobre a imagem.

* ``bits_per_pixel``. Ele informa o número de bits necessários para representar uma cor de pixel.
* ``size_line``. Porque os pixels da imagem não são armazenados em uma tabela 2D, mas todos em uma linha em um único array. Isso informa quantos pixels existem em cada linha da sua imagem e cada pixel é representado por 4 `chars`. Permitindo que você tenha acesso a cada pixel da imagem com a seguinte fórmula: _`X_position * 4 + Line_size * Y_position`_, que lhe dará o primeiro `char` do pixel.
* ``endian``. Pode ser 0 ou 1 dependendo do sistema e define como as cores são armazenadas. Para nós em 42 acredito que seja sempre armazenado da mesma forma: o primeiro caractere é azul, depois verde, vermelho e finalmente o alfa ou transparência do pixel. Cada valor vai de 0 a 255. _Você tem um exemplo de como usar isso e alterar cada pixel de uma imagem no arquivo color.c_.

Como eu salvo e gerencio neste projeto é criando um struct com todos os dados necessários para uma imagem.

````c
typedef struct	s_image
{
	void      *pointer;
	t_vector  size;
	char      *pixels;
	int       bits_per_pixel;
	int       line_size;
	int       endian;
}   t_image;
````

E depois ter uma função que cria a imagem e preenche as variáveis

````c
t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;
	
	img.pointer = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}
````

Para desenhar a imagem na janela, basta chamar ``mlx_put_image_to_window()``. Passando o ponteiro para a janela, a imagem e a posição. As coordenadas (0,0) da janela e as imagens estão no canto superior esquerdo.

````c
mlx_put_image_to_window(void *window_ptr, void *image_ptr, int x_position, int y_position);
````

---

### Cores

Algumas funções, como `mlx_pixel_put()` or `mlx_string_put()` pediram que você passe uma cor como um `int`. Isso está se referindo ao valor hexadecimal escrito como ``0xTTRRGGBB``. Você pode encontrar o valor hexadecimal de uma cor em qualquer seletor de cores (procure por _colour selector_ no google, ele também fornecerá os valores RGB dela). Tome cuidado para que a maioria deles forneça apenas o valor hexadecimal para o Vermelho, Verde e Azul. Portanto, pode ser necessário adicionar a transparência na frente deles.
Você pode gerar seus próprios valores de cor hexadecimal usando o deslocamento de bits. Mais sobre isso aqui: https://harm-smits.github.io/42docs/libs/minilibx/colors.html

E mais sobre imagens e cores aqui: https://github.com/keuhdall/images_example

---
### References
* https://gontjarow.github.io/MiniLibX/
* https://harm-smits.github.io/42docs/libs/minilibx
* https://github.com/qst0/ft_libgfx
* https://github.com/keuhdall/images_example

miniLibX manuals:
* man /usr/share/man/man3/mlx.1
* man /usr/share/man/man3/mlx_new_window.1
* man /usr/share/man/man3/mlx_pixel_put.1
* man /usr/share/man/man3/mlx_new_image.1
* man /usr/share/man/man3/mlx_loop.1

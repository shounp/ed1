/*
 * DCE05968 - Estruturas de Dados I
 * Funções responsaveis pelos filtros que podem ser aplicados na imagem.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Imagem.h"  /* Tipos e protótipos de funções que manipulam imagens */
#include "Filtros.h" /* Protótipo das funções responsáveis pelos filtros das imagens */

/* Função responsável por escurecer uma imagem
 * A função recebe um ponteiro para um struct Imagem e altera/escurece 
 * cada um de seus pixels em cada canal de cor (RGB).
 * 
 * Analise essa função com bastante atenção. Ela irá te auxiliar no entendimento 
 * do TAD Imagem e como outros filtros podem ser implementados.
 *
 * Você não precisa modificar essa função 
 */
void escurecerImagem(Imagem *img){
    int v;
    printf("Digite o fator de escurecimento: ");
    scanf("%d", &v);
    /* Cada canal de cor (RGB) de cada pixel é reduzido 'v' do valor.
     * Note que devemos garantir que o valor esteja entre 0 e 255.   
     * Como estamos subtraindo, verificamos apenas se o valor é >= 0 
     * Note também a utilização de expressão ternária e o cast (conversão) 
     * entre os valores Byte (unsigned int) e int. Esse cast evita erros nas 
     * operações matemáticas.
     */ 
    for (int h = 0; h < obtemAltura(img); h++) {
        for (int w = 0; w < obtemLargura(img); w++) {
            //Obtém o pixel da posição (h, w) da imagem 
            Pixel pixel = obtemPixel(img, h, w);
            //Modifica cada canal de cor do pixel
            pixel.cor[RED]   = (((int)pixel.cor[RED] - v) >= 0 ? ((int)pixel.cor[RED] - v) : 0);
            pixel.cor[GREEN] = (((int)pixel.cor[GREEN] - v) >= 0 ? ((int)pixel.cor[GREEN] - v) : 0);
            pixel.cor[BLUE]  = (((int)pixel.cor[BLUE] - v) >= 0 ? ((int)pixel.cor[BLUE] - v) : 0);
            //Grava o novo pixel na posição (h, w) da imagem
            recolorePixel(img, h, w, pixel);
        }
    }
}

/* Função responsável por clarear uma imagem
 * A função recebe um ponteiro para um struct Imagem e altera/clareia 
 * cada um de seus pixels em cada canal de cor (RGB).
 */
void clarearImagem(Imagem *img){
    int c;
    printf("Digite o fator de clareamento: ");
    scanf("%d", &c);
    for (int h = 0; h < obtemAltura(img); h++) {
        for (int w = 0; w < obtemLargura(img); w++) {
            Pixel pixel = obtemPixel(img, h, w);
            pixel.cor[RED]   = (((int)pixel.cor[RED] + c) <= 255 ? ((int)pixel.cor[RED] + c) : 255);
            pixel.cor[GREEN] = (((int)pixel.cor[GREEN] + c) <= 255 ? ((int)pixel.cor[GREEN] + c) : 255);
            pixel.cor[BLUE]  = (((int)pixel.cor[BLUE] + c) <= 255 ? ((int)pixel.cor[BLUE] + c) : 255);
            recolorePixel(img, h, w, pixel);
        }
    }
}

/* Função responsável por converter uma imagem colorida em escala de cinza
 * A função recebe um ponteiro para um struct Imagem e converte 
 * cada um de seus pixels em cada canal de cor (RGB) em uma tonalidade de cinza.
 * 
 * No pdf de descrição do EP existem duas estretégias para a implementação 
 * desse filtro. Você deve implementar uma delas ou pesquisar por outras alternativas. 
 */
void escalaDeCinzaImagem(Imagem *img){
    int cinzac;
    for (int h = 0; h < obtemAltura(img); h++) {
        for (int w = 0; w < obtemLargura(img); w++) {
            Pixel pixel = obtemPixel(img, h, w);
            cinzac = pixel.cor[RED]*0.3 + pixel.cor[GREEN]*0.59 + pixel.cor[BLUE]*0.11;
            pixel.cor[RED] = cinzac;
            pixel.cor[GREEN] = cinzac;
            pixel.cor[BLUE] = cinzac;
            recolorePixel(img, h, w, pixel);
        }
    }
}

/* Função responsável por aplicar o filtro de Sobel na imagem. 
 * Leia o pdf do EP para obter mais informações de como o filtro é implementado. 
 */
void filtroSobel(Imagem *img){
    int i,j;
    /* Dicas:
     * 1) Se quiser, pode ignorar as bordas das imagens
     * 2) Para o pixel na posição (h, w), obtenha os outros 8 pixels vizinhos e aplique a matriz gx e gy 
     *    em cada banda de cor do pixel. Combine o valor obtido por gx e gy e modifique o pixel de img.
     *    Lembre-se que a obtenção dos pixels deve ser a partir de uma cópia da imagem. 
     * 3) Verifique se o novo valor obtido para a banda de cor é um valor válido (entre 0 e 255).
    */
   Imagem *copiasobel = copiaImagem(img);

    for(i = 1; i < obtemAltura(copiasobel)-1; i++){
        for(j = 1; j < obtemLargura(copiasobel)-1; j++){
            int Gyred = 0, Gygreen = 0, Gyblue = 0, Gxred = 0, Gxgreen = 0, Gxblue = 0;
            int magnired = 0, magnigreen = 0, magniblue = 0;
           
            //matriz X

            Pixel pixel = obtemPixel(copiasobel, i-1, j-1);
            Gxred += pixel.cor[RED];
            Gxgreen += pixel.cor[GREEN];
            Gxblue += pixel.cor[BLUE];

            pixel = obtemPixel(copiasobel, i, j-1);
            Gxred += pixel.cor[RED]*2;
            Gxgreen += pixel.cor[GREEN]*2;
            Gxblue += pixel.cor[BLUE]*2;

            pixel = obtemPixel(copiasobel, i+1, j-1);
            Gxred += pixel.cor[RED];
            Gxgreen += pixel.cor[GREEN];
            Gxblue += pixel.cor[BLUE];

            pixel = obtemPixel(copiasobel, i-1, j+1);
            Gxred += pixel.cor[RED]*(-1);
            Gxgreen += pixel.cor[GREEN]*(-1);
            Gxblue += pixel.cor[BLUE]*(-1);

            pixel = obtemPixel(copiasobel, i, j+1);
            Gxred += pixel.cor[RED]*(-2);
            Gxgreen += pixel.cor[GREEN]*(-2);
            Gxblue += pixel.cor[BLUE]*(-2);

            pixel = obtemPixel(copiasobel, i+1, j+1);
            Gxred += pixel.cor[RED]*(-1);
            Gxgreen += pixel.cor[GREEN]*(-1);
            Gxblue += pixel.cor[BLUE]*(-1);

            //matriz Y

            pixel = obtemPixel(copiasobel, i-1, j-1);
            Gyred += pixel.cor[RED];
            Gygreen += pixel.cor[GREEN];
            Gyblue += pixel.cor[BLUE];

            pixel = obtemPixel(copiasobel, i-1, j);
            Gyred += pixel.cor[RED]*2;
            Gygreen += pixel.cor[GREEN]*2;
            Gyblue += pixel.cor[BLUE]*2;

            pixel = obtemPixel(copiasobel, i-1, j+1);
            Gyred += pixel.cor[RED];
            Gygreen += pixel.cor[GREEN];
            Gyblue += pixel.cor[BLUE];

            pixel = obtemPixel(copiasobel, i-1, j-1);
            Gyred += pixel.cor[RED]*(-1);
            Gygreen += pixel.cor[GREEN]*(-1);
            Gyblue += pixel.cor[BLUE]*(-1);

            pixel = obtemPixel(copiasobel, i-1, j);
            Gyred += pixel.cor[RED]*(-2);
            Gygreen += pixel.cor[GREEN]*(-2);
            Gyblue += pixel.cor[BLUE]*(-2);

            pixel = obtemPixel(copiasobel, i+1, j+1);
            Gyred += pixel.cor[RED]*(-1);
            Gygreen += pixel.cor[GREEN]*(-1);
            Gyblue += pixel.cor[BLUE]*(-1);

            // nos sites que eu olhei eles tiravam a raiz quadrada das somas das matrizes x e y ao quadrado.

            magnired = sqrt(pow(Gxred,2) + pow(Gyred,2));
            magnigreen = sqrt(pow(Gxgreen,2) + pow(Gygreen,2));
            magniblue = sqrt(pow(Gxblue,2) + pow(Gyblue,2));

            //vermelho

            if(magnired > 255)
                pixel.cor[RED] = 255;
            else if(magnired < 0)
                pixel.cor[RED] = 0;
            else
                pixel.cor[RED] = magnired;

            //verde   

            if(magnigreen > 255)
                pixel.cor[GREEN] = 255;
            else if(magnigreen < 0)
                pixel.cor[GREEN] = 0;
            else
                pixel.cor[GREEN] = magnigreen;
        
            // azul

            if(magniblue > 255)
                pixel.cor[BLUE] = 255;
            else if(magniblue < 0)
                pixel.cor[BLUE] = 0;
            else
                pixel.cor[BLUE] = magniblue;

            recolorePixel(img, i, j, pixel);
        }
    }
    liberaImagem(copiasobel);
}

/* Função responsável por aplicar a detecçõa de bordas de Laplace na imagem. 
 * Leia o pdf do EP para obter mais informações de como o filtro é implementado. 
 */
void deteccaoBordasLaplace(Imagem *img) {
    int i,j;
    
    Imagem *copiaLaplace = copiaImagem(img);
    
    for(i = 1; i < obtemAltura(copiaLaplace)-1; i++){
        for(j = 1; j < obtemLargura(copiaLaplace)-1; j++){
            int laplacered = 0, laplacegreen = 0, laplaceblue = 0;

            //matriz X

            Pixel pixel = obtemPixel(copiaLaplace, i-1, j);
            laplacered += pixel.cor[RED]*(-1);
            laplacegreen += pixel.cor[GREEN]*(-1);
            laplaceblue += pixel.cor[BLUE]*(-1);

            pixel = obtemPixel(copiaLaplace, i, j);
            laplacered += pixel.cor[RED]*4;
            laplacegreen += pixel.cor[GREEN]*4;
            laplaceblue += pixel.cor[BLUE]*4;

            pixel = obtemPixel(copiaLaplace, i, j-1);
            laplacered += pixel.cor[RED]*(-1);
            laplacegreen += pixel.cor[GREEN]*(-1);
            laplaceblue += pixel.cor[BLUE]*(-1);

            pixel = obtemPixel(copiaLaplace, i, j+1);
            laplacered += pixel.cor[RED]*(-1);
            laplacegreen += pixel.cor[GREEN]*(-1);
            laplaceblue += pixel.cor[BLUE]*(-1);

            pixel = obtemPixel(copiaLaplace, i+1, j);
            laplacered += pixel.cor[RED]*(-1);
            laplacegreen += pixel.cor[GREEN]*(-1);
            laplaceblue += pixel.cor[BLUE]*(-1);

            //vermelho

            if(laplacered > 255)
                pixel.cor[RED] = 255;
            else if(laplacered < 0)
                pixel.cor[RED] = 0;
            else
                pixel.cor[RED] = laplacered;

            //verde

            if(laplacegreen > 255)
                pixel.cor[GREEN] = 255;
            else if(laplacegreen < 0)
                pixel.cor[GREEN] = 0;
            else
                pixel.cor[GREEN] = laplacegreen;

            //azul

            if(laplaceblue > 255)
                pixel.cor[BLUE] = 255;
            else if(laplaceblue < 0)
                pixel.cor[BLUE] = 0;
            else
                pixel.cor[BLUE] = laplaceblue;

            recolorePixel(img, i, j, pixel);
        }
    }
    liberaImagem(copiaLaplace);
}

/* Função responsável por aplicar na imagem o filtro definido por você. Seja criativo! 
 * Filtros que apenas fazem algumas modificações simples em cada pixel 
 * (por exemplo, negativo, espelhar a imagem) não serão considerados.
 */


void meuFiltro(Imagem *img){
    int i,j;
    
    Imagem *meufiltro = copiaImagem(img);
    
    for(i = 1; i < obtemAltura(meufiltro)-1; i++){
        for(j = 1; j < obtemLargura(meufiltro)-1; j++){
            int meured = 0, meugreen = 0, meublue = 0;

            //matriz X

            Pixel pixel = obtemPixel(meufiltro, i-1, j-1);
            meured += pixel.cor[RED]*(-2);
            meugreen += pixel.cor[GREEN]*(-2);
            meublue += pixel.cor[BLUE]*(-2);

            pixel = obtemPixel(meufiltro, i-1, j);
            meured += pixel.cor[RED]*(-1);
            meugreen += pixel.cor[GREEN]*(-1);
            meublue += pixel.cor[BLUE]*(-1);

            pixel = obtemPixel(meufiltro, i, j-1);
            meured += pixel.cor[RED]*(-1);
            meugreen += pixel.cor[GREEN]*(-1);
            meublue += pixel.cor[BLUE]*(-1);

            pixel = obtemPixel(meufiltro, i, j);
            meured += pixel.cor[RED];
            meugreen += pixel.cor[GREEN];
            meublue += pixel.cor[BLUE];

            pixel = obtemPixel(meufiltro, i, j+1);
            meured += pixel.cor[RED];
            meugreen += pixel.cor[GREEN];
            meublue += pixel.cor[BLUE];

            pixel = obtemPixel(meufiltro, i+1, j);
            meured += pixel.cor[RED];
            meugreen += pixel.cor[GREEN];
            meublue += pixel.cor[BLUE];

            pixel = obtemPixel(meufiltro, i+1, j+1);
            meured += pixel.cor[RED]*2;
            meugreen += pixel.cor[GREEN]*2;
            meublue += pixel.cor[BLUE]*2;

            //transformando em negativo o resultado da matriz de relevo

            meured = 255 - meured;
            meugreen = 255 - meugreen;
            meublue = 255 - meublue;

            //vermelho

            if(meured > 255)
                pixel.cor[RED] = 255;
            else if(meured < 0)
                pixel.cor[RED] = 0;
            else
                pixel.cor[RED] = meured;

            //verde

            if(meugreen > 255)
                pixel.cor[GREEN] = 255;
            else if(meugreen < 0)
                pixel.cor[GREEN] = 0;
            else
                pixel.cor[GREEN] = meugreen;

            //azul

            if(meublue > 255)
                pixel.cor[BLUE] = 255;
            else if(meublue < 0)
                pixel.cor[BLUE] = 0;
            else
                pixel.cor[BLUE] = meublue;

            recolorePixel(img, i, j, pixel);
        }
    }
    liberaImagem(meufiltro);
}
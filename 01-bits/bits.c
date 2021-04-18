/*
 * Primeiro laboratório de Computadores e Programação
 *
 * A ideia do laboratório é mostrar ao aluno outras formas de fazer as operações
 * que ele já está acostumado a fazer, mas de formas diferentes.
 * Criamos esse desafio com o objetivo de fazê-lo pensar em diferentes formas de se
 * atingir o mesmo resultado. Se possível, tentando pensar em qual seria mais
 * eficiente.
 *
 * O aluno deverá usar apenas um subset de operações de C para realizar o que
 * for pedido no enunciado.
 *
 * Todas as operações permitidas serão especificadas em cada questão.
 *
 * Forma de avaliação:
 *      - Quantas operações o aluno utlizou para realizar a tarefa (dentro da quantidade aceitável)
 *      - Explicação do código -- deverá ser o mais claro possível (como qualquer
 *          código), imaginando que qualquer pessoa sem conhecimento prévio da
 *          matéria consiga entender o que foi feito.
 *      - As resoluções com menos operações do que a do monitor terão bonificação.
 *
 * Assinatura:
 *      Aluno: Leonardo Gonçalves | Kathleen Santana
 *      DRE: 111337097 | 113163232
 *      versão do GCC utilizada: 10.2.0
 *
 */

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include <stdint.h>


/* Número é par ou não
 *      Permitido:
 *          Operações: ~ & ^ | << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x é par, retorna 0 caso contrário
 *
 *      Exemplo:
 *          ehPar(0) -> 1
 *          ehPar(2) -> 1
 *          ehPar(7) -> 0
 */

int32_t ehPar(int32_t x) {
    /*
        Em binário, o estado do bit menos significativo nos mostra se o número é par ou ímpar.         
        Ex: 0001 em base 2 é equivalente a 1 na base 10. Já 0010 na base 2 é equivalente a 2 na base 10.
        
        Para a solução, tornamos o bit menos significativo o bit mais significativo, 
        "shiftando 31 a esquerda".
        Assim, o bit mais significativo passa a ser 0 ou 1.

        Caso o primeiro bit seja 0, o número é par e o resultado é zero
        Caso o primeiro bit seja 1, o número é ímpar e o resultado é diferente de zero. 

        Como queremos que a função retorne 1 caso a entrada seja par e 0 se a entrada for ímpar,
        usamos o operador ! para inverter o valor retornado pela operação.
    */
    
    return !(x<<31);
}

/*
 * Módulo 8
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 1
 *
 *      Retorna x % 8
 *
 *      Exemplo:
 *          mod8(1) -> 1
 *          mod8(7) -> 7
 *          mod8(10) -> 2
 */

int32_t mod8(int32_t x) {
    /*  
        Para resolver esse problema, primeiro vamos analisar alguns resultados fornecidos pela operação solicitada:
        1 mod8 = 1
        2 mod8 = 2
        3 mod8 = 3
        4 mod8 = 4
        5 mod8 = 5
        6 mod8 = 6
        7 mod8 = 7
        8 mod8 = 0
        9 mod8 = 1
        32 mod8 = 0

        Ou seja, devido a natureza da operação de módulo, o resultado deve ficar sempre entre
        0 e n-1, onde n é o valor do módulo. Assim, basta que façamos um AND com entre o número
        desejado e o valor do módulo a menos uma unidade. Ou seja, podemos fazer:
        
        resto = dividendo & (divisor - 1). 

        No nosso caso, buscamos o valor da operação de divisão com módulo 8, então ficamos com:
        
        resto = x & (8 - 1)   
    */
    return x & 7;
}

/* Negativo sem -
 *      Permitido:
 *          Operações: ~ & ^ | ! << >> +
 *
 *      Número máximo de operações: 5
 *      Monitor: 2
 *
 *      Retorna -x
 *
 *      Exemplo:
 *          negativo(1) -> -1
 *          negativo(42) -> -42
 */
int32_t negativo(int32_t x) {
    /* 
        Uma das formas de representar números negativos é usando
        complemento a dois. 
        Ou seja, converter o número em binário,
        inverter todos os bits do seu número e somar 1. 
        O sistema reconhece que um número é negativo quando seu bit mais 
        significativo, ou seja, o bit mais à esquerda é 1.
    */
    return (~x)+1;
    
}

/* Implementação do & usando bitwise
 *      Permitido:
 *          Operações: ~ ^ | ! << >>
 *
 *      Número máximo de operações: 7
 *      Monitor: 4
 *
 *      Retorna x & y
 *
 *      Exemplo:
 *          bitwiseAnd(1, 2) -> 0
 *              01 & 10 -> 00
 *          bitwiseAnd(3, 11) -> 3
 *              11 & 1011 -> 0011
 */
int32_t bitwiseAnd(int32_t x, int32_t y) {
	/* 
        O operador bitwise AND (&) retorna 1 em cada posição de byte
        para a qual os bits correspondentes de ambos os operandos são 1.
        Para fazer uma operação equivalente, podemos fazer um OR do 
        complementoa dois dos dois operandos. Lembrando que o complemento a dois
        apenas irá "flipar" os bits.
        Ao fazer isso, iremos setar todos os bits que casarem para 1. 
        Vamos lembrar que:
        
        0 | 0 = 0
        1 | 0 = 1
        0 | 1 = 1
        1 | 1 = 1.
        
        Ou seja, cada par de bits em que ambos não sejam zero irá virar 1.
        Agora, basta fazer o complemento a dois do valor que encontramos na 
        operação acima para novamente flipar o resultado. 

        Fazendo um paralelo com Lei de Morgan, estamos buscando o seguinte:
        ¬((¬x)|(¬y)) = (¬(¬x))&(¬(¬y)) = x&y
        
    */
    return ~((~x)|(~y));
}

/* Igual sem ==
 *      Permitido:
 *          Operações: ~ & ^ | << >> !
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x == y, 0 caso contrário
 *
 *      Exemplo:
 *          ehIgual(10, 10) -> 1
 *          ehIgual(16, 8) -> 0
 */
int32_t ehIgual(int32_t x, int32_t y) {
    
	/*
        Para resolver esse problema, vamos usar o XOR, que ao comparar os bits
        retorna 1 se ambos operandos são opostos e 0 caso contrário. 
        Então, caso x e y sejam iguais, a operação deve retornar 0, e caso contrário, 
        irá retornar um número diferente de 0.

        Como o resultado esperado deve ser 1 se os números forem iguais
        e 0 caso contrário, precisamos utilizar o operador not para inverter 
        o valor obtido pelo XOR.
    */

    return !(x^y);
}

/* Limpa bit n
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 4
 *      Monitor: 3
 *
 *      Retorna o x com o bit n = 0,
 *      n pode variar entre 0 e 31, do LSB ao MSB
 *
 *      Exemplo:
 *          limpaBitN(3, 0) -> 2
 *          limpaBitN(3, 1) -> 1
 */
int32_t limpaBitN(int32_t x, int8_t n) {

	/*
        Dado um número x, o objetivo e retornar esse número com o bit
        n "limpo". Ou seja:
        Quando for, 1 "apaga" e vira 0 
        Quando for 0, permanece 0
        
        Um AND bit a bit de qualquer bit com um bit de reset
        resulta em um bit de reset. Isso quer dizer que: 
        
        0 AND 0 = 0
        1 AND 0 = 0
        
        Logo, podemos executar um AND bit a bit de um número
        com um bit de redefinição é a ideia mais prática. 
        Para isso, fazemos um shift a esquerda de 1 por n posições,
        fazendo com o que o bit queremos apagar seja setado em 1,
        "flipamos" o conjunto de bits usando o operador ~ e por fim,
        fazemos o AND entre a nossa entrada e a "máscara" que criamos, 
        apagando assim o bit da posição n da entrada.
        Ou seja, fazemos x = x & ~ (1 << n), onde n é o bit a ser apagado. 
    */

    return x & ~(1 << n);
}

/*
 * Bit na posição p do inteiro x
 *      Permitido:
 *          Operações bitwise: << >> | & + -
 *
 *      Número máximo de operações: 6
 *      Monitor: 2
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser apenas 0 ou 1
 *
 *      p será um valor entre 0 e 31
 *
 *      Exemplo:
 *          23 em binário: 0   0 ... 0 1 0 1 1 1
 *               posições: 31 30 ... 5 4 3 2 1 0
 *
 *          bitEmP(23, 31) -> 0
 *          bitEmP(23, 5) -> 0
 *          bitEmP(23, 4) -> 1
 *          bitEmP(23, 3) -> 0
 *          bitEmP(23, 2) -> 1
 *          bitEmP(23, 1) -> 1
 *          bitEmP(23, 0) -> 1
 *
 */
int32_t bitEmP(int32_t x, uint8_t p) {
    /* 
        Para resolver esse problema, primeiro fazemos
        o deslocamento com um shift a direita em p posições. 
        Isso faz com que o p fique no ponto mais distante a 
        direita do número x. Então, fazemos o AND com 1 para 
        definir o bit que queremos da posição desejada.

    */
    return (x >> p) & 1;
    
}

/*
 * Byte na posição p do inteiro x
 *      Permitido:
 *          Operações: << >> | ! &
 *
 *      Número máximo de operações: 6
 *      Monitor: 3
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser entre 0 e 0xFF
 *
 *      p será um valor entre 0 e 3
 *      0 retorna LSB
 *      3 retorna MSB
 *
 *      Exemplo:
 *          byteEmP(0x12345678, 0) -> 0x78
 *          byteEmP(0x12345678, 1) -> 0x56
 *          byteEmP(0x12345678, 2) -> 0x34
 *          byteEmP(0x12345678, 3) -> 0x12
 *
 */

int32_t byteEmP(int32_t x, uint8_t p) {
    /*
        Primeiro, encontramos a posição do byte que queremos 
        (em bits) através da operação p << 3 (isso é equivalente a
        fazer 8 * n). 
        Em seguida, movemos o byte procurado para a posição mais baixa, 
        fazendo x >> (p << 3).
        Agora, só precisamos fazer um AND com a máscara 0xFF para 
        retornar o valor do byte que procuramos, já que um AND entre qq valor X e 1 será X, 
        desde que X seja diferente de zero.

    */
    return (x >> (p << 3)) & 0xFF;
}

/*
 * Seta byte na posição p do inteiro x como y
 *      Permitido:
 *          Operações: << >> | ~ ! &
 *
 *      Número máximo de operações: 7
 *      Monitor: 5
 *
 *      Retorna x com o valor y no byte da posição p
 *
 *      p será um valor entre 0 e 3
 *      0 retorna LSB
 *      3 retorna MSB
 *
 *      Exemplo:
 *          setaByteEmP(0x12345678, 0xFF, 0) -> 0x123456FF
 *          setaByteEmP(0x12345678, 0xFF, 1) -> 0x1234FF78
 *          setaByteEmP(0x12345678, 0xFF, 2) -> 0x12FF5678
 *          setaByteEmP(0x12345678, 0xFF, 3) -> 0xFF345678
 *
 */
int32_t setaByteEmP(int32_t x, int32_t y, uint8_t p) {
    return ((x >> p) & 0x0000FFFF) | y;
}

/*
 * Minimo
 *      Permitido:
 *          Operações: << >> | ^ < > ~ ! & -
 *
 *      Número máximo de operações: 15
 *      Monitor: 5
 *
 *      Retorna o menor numero entre x e y
 *
 *      Exemplo:
 *          minimo(10, 15) -> 10
 *          minimo(-2, -1) -> -2
 *          minimo(-1, 2) -> -1
 *
 */

int32_t minimo(int32_t x, int32_t y) {
/*
    Para resolver isso, primeiro vamos observar algumas coisas
    Olhando para a expressão -(x < y), sabemos que ela será avaliada
    como true caso o valor de x seja menor que y. Nesse caso, a expressão
    dentro dos parenteses será 1 e no final, a expressão toda será -1.
    Caso contrário, a expressão deverá retornar 0.

    Agora, vamos avaliar a seguinte expresão:

    (x ^ y) & -(x < y)

    Ou seja, fazendo XOR bit a bit entre x e y e depois um AND com um valor
    que pode ser 0 ou -1 (a depender do resultado de x < y).

    Sabemos que um AND bit a bit com 0 fará todos os bits do resultado irem
    para zero, então a expressão x ^ y seria avaliada como zero.
    Caso o valor da segunda parte da expressão seja -1, todos os bits serão 
    definidos como 1.

    Agora, fazendo um XOR com o segundo parametro de entrada, teriamos o seguinte:
    
    y ^ (0) // o valor de x é maior ou igual a y
    y ^ (x ^ y) // y é maior

    No primeiro caso, um XOR com 0 resulta no valor do operando.
    No segundo caso, o XOR deve retornar y
*/

    return y ^ ((x ^ y) & -(x < y));  
}

/*
 * Negação lógica sem !
 *      Permitido:
 *          Operações: << >> | & + ~
 *
 *      Número máximo de operações: 15
 *      Monitor: 5
 *
 *      Retorna 1 se x == 0, retorna 0 caso contrário
 *
 *      Exemplo:
 *          negacaoLogica(0) -> 1
 *          negacaoLogica(37) -> 0
 *
 */

int32_t negacaoLogica(int32_t x) {

    /*
        Primeiro, fazemos um deslocamento a direita do valor de entrada com 31, 
        que seria equivalente a sua negação.
    */
    return ((x >> 31) | ((~x + 1) >> 31)) + 1;
}

void teste(int32_t saida, int32_t esperado) {
    static uint8_t test_number = 0;
    test_number++;
    if(saida == esperado)
        printf(ANSI_COLOR_GREEN "PASSOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            saida, esperado);

    else
        printf(ANSI_COLOR_RED "%d: FALHOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            test_number, saida, esperado);
}

int main() {
    puts(ANSI_COLOR_BLUE "Primeiro lab - bits" ANSI_COLOR_RESET);
    puts("");

    puts("Teste: ehPar");
    teste(ehPar(2), 1);
    teste(ehPar(1), 0);
    teste(ehPar(3), 0);
    teste(ehPar(13), 0);
    teste(ehPar(100), 1);
    teste(ehPar(125), 0);
    teste(ehPar(1024), 1);
    teste(ehPar(2019), 0);
    teste(ehPar(2020), 1);
    teste(ehPar(-1), 0);
    teste(ehPar(-27), 0);
    teste(ehPar(-1073741825), 0);
    teste(ehPar(1073741824), 1);
    teste(ehPar(2147483647), 0);
    teste(ehPar(-2147483648), 1);
    teste(ehPar(0), 1);
    puts("");

    puts("Teste: mod8");
    teste(mod8(0), 0);
    teste(mod8(4), 4);
    teste(mod8(7), 7);
    teste(mod8(8), 0);
    teste(mod8(-1), 7);
    teste(mod8(-8), 0);
    teste(mod8(2147483647), 7);
    teste(mod8(-2147483648), 0);
    puts("");

    puts("Teste: negativo");
    teste(negativo(0), 0);
    teste(negativo(1), -1);
    teste(negativo(-1), 1);
    teste(negativo(2147483647), -2147483647);
    teste(negativo(-2147483647), 2147483647);
    teste(negativo(-2147483648), 2147483648);
    puts("");

    puts("Teste: bitwiseAnd");
    teste(bitwiseAnd(1, 3), 1);
    teste(bitwiseAnd(-1, 0), 0);
    teste(bitwiseAnd(-1, 0x7FFFFFFF), 0x7FFFFFFF);
    teste(bitwiseAnd(0b0100, 0b1100), 0b0100);
    puts("");

    puts("Teste: ehIgual");
    teste(ehIgual(1,1), 1);
    teste(ehIgual(1,0), 0);
    teste(ehIgual(0,1), 0);
    teste(ehIgual(-1,1), 0);
    teste(ehIgual(-1,-1), 1);
    teste(ehIgual(2147483647,-1), 0);
    teste(ehIgual(2147483647,-2147483647), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    puts("");

    puts("Teste: limpaBitN");
    teste(limpaBitN(1,0), 0);
    teste(limpaBitN(0b1111,1), 0b1101);
    teste(limpaBitN(15,3), 7);
    teste(limpaBitN(-1,31), 2147483647);
    teste(limpaBitN(-1,0), -2);
    teste(limpaBitN(2147483647, 30), 1073741823);
    puts("");

    puts("Teste: bitEmP");
    teste(bitEmP(1, 0), 1);   //    b01 => retorna 1
    teste(bitEmP(1, 1), 0);   //    b01 => retorna 0
    teste(bitEmP(2, 0), 0);   //    b10 => retorna 0
    teste(bitEmP(2, 1), 1);   //    b10 => retorna 1
    teste(bitEmP(9, 2), 0);   //  b1001 => retorna 0
    teste(bitEmP(-4194305, 22), 0);
    teste(bitEmP(9, 3), 1);
    teste(bitEmP(16, 3), 0);
    teste(bitEmP(0x1 << 5, 4), 0);
    teste(bitEmP(0x1 << 31, 31), 1);
    teste(bitEmP(-1073741825, 30), 0);
    teste(bitEmP(-1073741825, 31), 1);
    puts("");

    puts("Teste: byteEmP");
    teste(byteEmP(0x766B, 1), 0x76);
    teste(byteEmP(0x766B, 0), 0x6B);
    teste(byteEmP(0x8420, 0), 0x20);
    teste(byteEmP(0x12345678, 3), 0x12);   // retorna 0x12
    teste(byteEmP(0x12345678, 2), 0x34);   // retorna 0x34
    teste(byteEmP(0x12345678, 1), 0x56);   // retorna 0x56
    teste(byteEmP(0x12345678, 0), 0x78);   // retorna 0x78
    teste(byteEmP(0x321, 1), 0x03);        // retorna 0x03
    teste(byteEmP(0x321, 0), 0x21);        // retorna 0x21
    puts("");

    puts("Teste: setaByteEmP");
    teste(setaByteEmP(0x00, 0xFF, 0), 0x000000FF);
    teste(setaByteEmP(0x00, 0xFF, 1), 0x0000FF00);
    teste(setaByteEmP(0x00, 0xFF, 2), 0x00FF0000);
    teste(setaByteEmP(0x00, 0xFF, 3), 0xFF000000);
    teste(setaByteEmP(0x01234567, 0x33, 2), 0x01334567);
    teste(setaByteEmP(0xdeadbeef, 0x00, 0), 0xdeadbe00);
    teste(setaByteEmP(0xdeadbeef, 0x00, 1), 0xdead00ef);
    puts("");

    puts("Teste: minimo");
    teste(minimo(0,1), 0);
    teste(minimo(0,10), 0);
    teste(minimo(1, 128), 1);
    teste(minimo(-1, 0), -1);
    teste(minimo(-1, -2), -2);
    teste(minimo(2147483647, 2147483646), 2147483646);
    teste(minimo(-2147483648, -2147483647), -2147483648);
    teste(minimo(-2147483648, -1), -2147483648);
    puts("");

    puts("Teste: negacaoLogica");
    teste(negacaoLogica(0), 1);
    teste(negacaoLogica(1), 0);
    teste(negacaoLogica(-1), 0);
    teste(negacaoLogica(64), 0);
    teste(negacaoLogica(-64), 0);
    teste(negacaoLogica(2147483647), 0);
    teste(negacaoLogica(-2147483648), 0);
    puts("");

}

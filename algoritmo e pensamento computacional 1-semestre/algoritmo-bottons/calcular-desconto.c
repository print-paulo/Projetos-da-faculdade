#include <stdio.h>

int main() {
    float valor_unitario, quantidade, desconto, valor_excedente, valor_descontado, valor_total;
    printf("Digite o valor de cada unidade do produto: ");
    scanf("%f", &valor_unitario);
    
    printf("Digite o valor do desconto em %%: ");
    scanf("%f", &desconto);
    desconto = desconto / 100;
    
    printf("Digite a quantidade vendida: ");
    scanf("%f", &quantidade);

    if (quantidade <= 100) { 
        valor_total = quantidade * valor_unitario;
        printf("Valor total a pagar: R$ %.2f\n", valor_total);
        return 0;
    }
    else {  //Desconto aplica apenas para compras acima de 100 unidades
        valor_excedente = quantidade - 100;
        valor_descontado = (valor_excedente * valor_unitario) * desconto;
        valor_total = (100 * valor_unitario) + (valor_excedente * valor_unitario) - valor_descontado;
        printf("Valor total a pagar com desconto: R$ %.2f\n", valor_total); 
        return 0;
    }
}

/* *********************************************************************** *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *  Copyright (C) 2021 by Alex Bruno Seabra                                 *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *  To contact the author, please write to:                                 *
 *  Name: Alex Bruno Seabra <aalexbrunno@gmail.com>                         *
 *  Webpage: http://beco.poli.br/~username                                  *
 *  Phone: (81) 98735-8802                                                  *
 * ************************************************************************ *
 * 
 */



#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(void)
{
    int vetor[20] = {0};
    int maior=0;
    int menor=10000;
    int media=0;

    srand(time(NULL));

    printf("valores aleatorios\n");
    

    for(int i = 0; i < 20; i++)
    {
        vetor[i] = rand() % 10000;

        if(vetor[i] > maior)
            maior = vetor[i];

        if(vetor[i] < menor)
            menor = vetor[i];
    }

    media = (maior + menor) / 2;

    printf("Maior valor: %i\n", maior);
    printf("Menor valor: %i\n", menor);
    printf("Media entre o maior e o menor: %i\n", media);

    return 0;
}

# Projeto-2---Leandro



Exemplo dos arquivos:





hash.txt  (estado inicial, após ser criado)
______________________________________________________________________________________________________________________________________
2
2,0

2,0

2,0

2,0

_____________________________________________________________________________________________________________________________________
Onde:
O número "2", da linha 9, indica  profundidade global do hash.
Os números "2,0", das linhas 10,12,14 e 16 indicam a profundidade local do hash e o número de registros naquela página, respectivamente.

hash.txt (após inserir 2 arquivos em buckets diferentes)
______________________________________________________________________________________________________________________________________
2
2,1
100,1
2,0

2,0

2,1
407,2
______________________________________________________________________________________________________________________________________
Onde:
Os números "123" e "1", na linha 27, indicam o CPF e o número da linha onde o registro se encontra, no arquivo clients.txt.  Eles são separados pelo caractere ",".  Observe que, no primeiro bucket, ele aponta que existe 1 registro, assim como no 3 bucket.  Registros devem ser separados por |, caso estejam no mesmo bucket.




Clientes.txt (estado inicial, após ser criado)
->vazio

Clientes.txt (após inserir os 2 registros)
______________________________________________________________________________________________________________________________________
100|Luiz Henrique|10000,00|0,00
407|Amador Sampaio|3000,00|3000,00
______________________________________________________________________________________________________________________________________


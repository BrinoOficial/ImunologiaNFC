# ImunologiaNFC
Projeto para explicar imunização primária e secundária de forma divertida. Com um módulo NFC MRFC522(que tem um desenho de um garoto colado), nós demonstramos os estágios de saúde do "Marcelo", um garoto que foi contaminado por diferentes vírus(cartões NFC). Um LED RGB ilustra o estado do paciente.

# Como Aplicar
Marcelo é um garoto que saiu para brincar com seus amigos. Por azar, ele entrou em contato com um vírus (cartão NFC do Vírus se aproxima do Marcelo). Como o Marcelo nunca havia sido contamidado por este patógeno, ele vive todo o processo de imunização primária. Sua saúde (LED brilhando em verde), mudará para o status de contaminado(LED brilha em azul), depois para doente (LED brilha em vermelho) e, por último, volt a ficar saudável (LED Brilha em verde).
Agora, se ele entrar em contato novamente com o vírus, ele não passará pelo estágio de doente (o led brilhará em verde, depois azul, depois verde).

Por último, o aluno pode testar um novo cartão, que representa um vírus que sofreu mutação em seu código genético. Como o vírus é diferente, ele vivenciará todo o processo de imunização primária novamente.

# Materiais
Para montar esse projeto foram usados os seguintes materiais:

* Módulo RFID MRFC522
* 2 Tags NFC Padrão S50
* Protoboard
* LED RGB ânodo comum
* Resistor 330 Ohms
* Jumpers/fios

# Circuito
A montagem do circuito pode ser visto na imagam abaixo:
![Imagem do circuito](https://github.com/BrinoOficial/ImunologiaNFC/blob/master/Circuito/Circuito.png)

# Código
Antes de baixar o código, instale a biblioteca NFC em : https://github.com/BrinoOficial/NFC
Obs: os passos para instalação está disponível no link acima.
O código está disponível na linguagem Br.ino e na Arduino dentro da pasta "NFCInfeccao".

# Projeto finalizado
Seguem algumas imagem do resultado do projeto e um breve vídeo de seu funcionamento.
![Vídeo funcionando](https://github.com/BrinoOficial/ImunologiaNFC/blob/master/Fotos/IMG_5357.MOV)
![Imagem do Projeto](https://github.com/BrinoOficial/ImunologiaNFC/blob/master/Fotos/IMG_5352.jpg)
![Imagem do Projeto](https://github.com/BrinoOficial/ImunologiaNFC/blob/master/Fotos/IMG_5353.jpg)
![Imagem do Projeto](https://github.com/BrinoOficial/ImunologiaNFC/blob/master/Fotos/IMG_5354.jpg)
![Imagem do Projeto](https://github.com/BrinoOficial/ImunologiaNFC/blob/master/Fotos/IMG_5355.jpg)

# Mais projetos
Mais projetos como esse podem ser encontrados no nosso site: https://brino.cc

# Encontrou algum erro?
Caso tenha encontrado algum erro ou tenha alguma sugestão, mande email para: contato@brino.cc ou crie um issue neste projeto



# o que essas variaveis sao?
 # - type: text, portanto: 

 texto esqInter = ""
 texto dirInter = "" # o que essas variaveis sao?
 
 texto esqExter = ""
 texto dirExter = ""

 texto centro = ""


 tarefa seguirLinha {
  
 # substituindo sensor por variavel 


  #sensores internos 
  dirInter = cor(2) # sensor de cor interno esquerdo
  esqInter = cor(4) # sensor de cor interno diretoesqinter = cor(4) #sensor de cor interno esquerdo
  
  #sensores externos
  dirExter = cor(1)
  esqExter = cor(5)

  centro = cor(3)


 #escrever(1, cor(1))  
 #escrever(2, cor(2))  # apenas para ter o controle no console. 
 #escrever(3, cor(3))
 #escrever(4, cor(4))
 #escrever(5, cor(5))
 
 #teste
enquanto (1 > 0) farei{
  se (centro == "PRETO") entao {
   frente(130)
 }
 se ((esqInter != "BRANCO") e (dirInter == "BRANCO")) entao {
   se (esqExter != "BRANCO") entao {
     frente(100)
     esquerda(200)
     esperar(1000)
     frente(130)
   }
   senao {
     esquerda(200)
     esperar(1000)
   }   
 }
 se ((esqInter == "BRANCO") e (dirInter != "BRANCO")) entao {
  se (dirExter != "BRANCO") entao {
   frente(100)
   direita(200)
   esperar(1000)
   frente(130)
 }
 senao {
  direita(200)
  se (dirInter == "VERDE") entao{
    frente(100)
    esperar(1000)
    direita(200)
    frente(130)
  }
}

} 

}
 }

tarefa acordaAtuador{
  levantar(6000)
}

booleano objeto = verdadeiro



 inicio


enquanto (1 > 0) farei{

  acordaAtuador()

objeto = temalgo(3, 5, 65)

se (objeto == verdadeiro) entao {
escrever(1, "Obstáculo encontrado")
direita(200)
esperar(3000)
frente(200)
esperar(2000)
esquerda(200)
esperar(3000)
frente(100)
esperar(200)

#seguirLinha()


} senao {
  escrever(2, "nada aqui")
  seguirLinha()
}


}

 

fim



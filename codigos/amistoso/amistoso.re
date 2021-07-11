# o que essas variaveis sao?
 # - type: text, portanto: 

 texto esqInter = ""
 texto dirInter = "" # o que essas variaveis sao?

 texto esqExter = ""
 texto dirExter = ""


#OBSTÁCULO

booleano sensorUm = verdadeiro
booleano sensorDois = verdadeiro
booleano sensorTres = verdadeiro


# booleano sensorAtuador = verdadeiro

#tarefa levantarAtuador{
#  levantar(800)
#}

inicio


farei{

#sensorAtuador = temalgo(2,5,10)
#se (sensorAtuador == falso) entao {
#   levantarAtuador()

 # substituindo sensor por variavel 

  #sensores internos 
  dirInter = cor(2) # sensor de cor interno esquerdo
  esqInter = cor(4) # sensor de cor interno diretoesqinter = cor(4) #sensor de cor interno esquerdo

  #sensores externos
  dirExter = cor(1)
  esqExter = cor(5)


 # escrever(1, cor(1))  #DIREITA
 # escrever(2, cor(2))  # apenas para ter o controle no console. 
 # escrever(3, cor(3))
 # escrever(4, cor(4))
 # escrever(5, cor(5))

 escrevernumero(1, ultra(1))
 escrevernumero(2, ultra(2))
 escrevernumero(3, ultra(3))

 #teste
 sensorTres = temalgo(3, 5, 20)
 se (sensorTres == verdadeiro) entao {
  escrever(3, "Obstáculo encontrado")
  esquerda(300)
  esperar(3000)
  frente(100)
  esperar(1000)
  sensorUm = temalgo(1, 5, 10)
  sensorDois = temalgo(2, 1, 10)
  se (sensorDois == verdadeiro) entao{
    escrever(2, "O 2 achou algo aqui")
    frente(100)
    esperar(1000)
    } senao {


      esperar(1300)
      direita(300)
      esperar(3000)
      frente(100)
      esperar(1000)
      direita(200)
      esperar(2000)
    }
    } senao {

      se ((esqInter == "BRANCO") e (dirInter == "BRANCO")) entao {
       frente(130)
     }
     se ((esqInter != "BRANCO") e (dirInter == "BRANCO")) entao {
       se (esqExter != "BRANCO") entao {
         esquerda(300)
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
       direita(300)
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

    } senao {
      se ((esqInter == "BRANCO") e (dirInter == "BRANCO")) entao {
       frente(130)
     }
     se ((esqInter != "BRANCO") e (dirInter == "BRANCO")) entao {
       se (esqExter != "BRANCO") entao {
         esquerda(300)
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
       direita(300)
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

}} enquanto( 1 > 0 )


fim
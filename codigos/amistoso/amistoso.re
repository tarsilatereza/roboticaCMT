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


# RAMPA - INCLINAÇÃO 

numero angulo = 0


# booleano sensorAtuador = verdadeiro

#tarefa levantarAtuador{
#  levantar(800)
#}






 tarefa desviar {
 sensorTres = temalgo(3, 5, 32)


    escrever(1, "obstáculo encontrado")
    escrevernumero(2, ultra(3))
    tras(100)
    esperar(1000)
    esquerda(200)
    esperar(3000)
    frente(200)
    esperar(1600)
    direita(300)
    esperar(2000)
    frente(100)
    esperar(2000)
    direita(200)
    esperar(3000)
 
}


inicio


enquanto (1 > 0) farei {

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






  




# escrevernumero(1, ultra(1))
 #escrevernumero(2, ultra(2))
 #escrevernumero(3, ultra(3))

 #teste
 escrevernumero(2,luz(3))

    se ((ultra(3) < 10) e (angulo == 0))  entao {
    desviar()
  } senao {


      se ((esqInter == "BRANCO") e (dirInter == "BRANCO")) entao {
       frente(130)
     }
     se ((esqInter != "BRANCO") e (dirInter == "BRANCO")) entao {
       se (esqExter != "BRANCO") entao {
        frente(100)
        esperar(700)
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
      } senao se (esqInter == "VERDE") entao {
        frente(100)
        esperar(1000)
        esquerda(200)
        frente(130)
      } 
    }
  }

 
}

} }


fim
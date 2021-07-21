# 3º amistoso

tarefa levantarAtuador {
  escrever(1, "recolhendo atuador...")
  girarbaixo(500)
  esperar(2000)
  limparconsole()
}

#QUANDO COLOCO ATUADOR, PARA DE FUNCIONAR.


tarefa irPraFrente {
	escrever(1, "é pra frente que se anda")
	frente(200)
}


tarefa virarEsquerda {
	escrever(1, "curva para esquerda")
	direita(300)
	esperar(1000)
	limparconsole()

}


tarefa virarDireita {
	escrever(1, "curva para direita")
	direita(300)
	esperar(1000)
	limparconsole()

}

tarefa noventaEsquerda {
	escrever(1, "curva de 90 graus para esquerda")
	frente(100)
	esperar(1000)
	esquerda(300)
	esperar(3100)
	limparconsole()
}


tarefa noventaDireita {
	escrever(1, "curva de 90 graus para direita")
	frente(100)
	esperar(1000)
	direita(300)
	esperar(3100)
	limparconsole()
}




booleano sensorTres = verdadeiro



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


tarefa subirRampa {
  escrevernumero(2, inclinacao())
}

numero angulo = inclinacao()



texto dirInter = ""
texto dirExter = ""

texto esqInter = ""
texto esqExter = ""




 tarefa seguirLinha {


  dirInter = cor(2) # sensor de cor interno esquerdo
  esqInter = cor(4) # sensor de cor interno diretoesqinter = cor(4) #sensor de cor interno esquerdo

  #sensores externos
  dirExter = cor(1)
  esqExter = cor(5)



      se ((esqInter == "BRANCO") e (dirInter == "BRANCO")) entao {
        irPraFrente()
     }
     se ((esqInter != "BRANCO") e (dirInter == "BRANCO")) entao {
       se (esqExter != "BRANCO") entao {
         noventaEsquerda()
       }
       senao {
         esquerda(200)
         esperar(1000)
       }   
     }
     se ((esqInter == "BRANCO") e (dirInter != "BRANCO")) entao {
      se (dirExter != "BRANCO") entao {
       noventaDireita()
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
 }



inicio 


enquanto (1 > 0) farei {
  levantarAtuador()
  esperar(1000)
	seguirLinha()

	se ((ultra(3) < 10) e (angulo == 0))  entao {
		desviar()
	} senao {
		seguirLinha()
	}
}
fim
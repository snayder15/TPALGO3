#encoding: utf-8
import numpy as np
from numpy import *
from time import time
import sys
import os

from distutils.core import setup, Extension

ejecutable3 = "./tiempo"
archivo_salida3 = "tiempo3.dat"

rango_tamanio = 5,10,15,20,25
ejemplo_1 = [0,7,1,2,2,1,5,0]
ejemplo_2 = [3,11,0,1,3,5,2,4,1,0,9,3]
ejemplo_3 = [1,2,3,4,5,6,7,5,9,1,2,3]
ejemplo_4 = [1,2,3,1,2,3,4,5,6,7,5,9]

rango_tamanio= 5,10,15,20,25,30,35,40,45,50,100,200,300,400,500,600
rango_bt= 5,7,10,12,15,17,20,21,22,23,24,25,27,28,29,30,31,32,33,34,35,36,37,38,39
repes = 10

def armarArgumentos(ejecutable, ciudades,rutas,repes=10):
	# Esto arma los argumentos para call:
	# 	El primer elemento de la lista es el programa que se va a correr
	# 	El resto son los argumentos para este programa.
	#	O sea, si tenemos la lista l = [exec, a1, a2, a3] y hacemos call(l)
	#   es como si escribiéramos en la terminal exec a1 a2 a3 y apretáramos enter.
	#	Obs: todos tienen que ser strings.
	return [ejecutable,str(ciudades)] + map(str,rutas)

usage1 = "\nerror, parametros incorrectos\n\
modo de ejecucion python correr_experimentos.py t|a archivo_casos archivo_salida\n\
t para correr casos de prueba \n\
a para correr instancias aleatorias\n"

if __name__ == '__main__':
	from sys import argv
	from subprocess import call
	if(len(argv)<2):
		print usage1
		sys.exit()
	if(argv[1]=='t'):
		archivo_salida=archivo_salida3
		ejecutable=ejecutable3
		if(len(argv)>=3):
			with open(argv[2],'r') as in_file:
				#terminar aca
				if(len(argv)>=4):
					archivo_salida=argv[3]
				with open(archivo_salida, 'a') as f:
					for line in in_file:
						path, file_name = os.path.split(argv[2])
						test_name=line.split(" ")[0]
						test=path+"/"+test_name
						sol=line.split(" ",1)[1]
						with open(test,'r') as test_file:
							ciudades=int(test_file.readline())
							rutas=[]
							for linea in test_file:
								linea=linea.rstrip()
								arreglo=linea.split(' ') 
								rutas+=map(int,arreglo)
							args =  armarArgumentos(ejecutable, ciudades, rutas)
							print "Test "+test_name+" de tamanio: "+str(ciudades)+" solucion: "+str(sol) 
						 	call(args, stdout=f)
						 	print " "
						test_file.close()
				f.close()
			in_file.close()
			sys.exit()
		else:
			print "error,falta el archivo de entrada"
			sys.exit()
	elif(argv[1]=="a"):
		ejecutable=ejecutable3
		rango=rango_tamanio
		if(argv>=3):
			archivo_salida=argv[2]
		with open(archivo_salida, 'a') as f:
			for i in rango:
				for k in range(0,i*i):
					for j in range(0,repes):
				 		arreglo=np.array([random.randint(0,i+1) for j in range(i)])
				 		print "tamanio:"+str(i)+" secuencia: "+ str(arreglo)
						args =  armarArgumentos(ejecutable, i, arreglo, 1)
				 		call(args,stdout=f)
		 	f.close()
	else:
		print usage1
		sys.exit()
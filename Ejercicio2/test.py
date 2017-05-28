#encoding: utf-8
import numpy as np
from numpy import *
from time import time
import sys
import os
from random import randint,shuffle
import random

from distutils.core import setup, Extension

ejecutable3 = "./tiempo"
archivo_salida3 = "tiempo2.dat"
temp_file="temp"

maximo_n=200
max_rutas=90	
maximo_peaje=29 #se eleva 2 ^ maximo peaje
max_intancias=200

def generar_rutas(ciudades,cant_rutas,max_peaje=150):
	n = int (ciudades)
	#creo las aristas normales
	completo=n*(n-1)/2
	if(cant_rutas>completo):
		cant_rutas=completo
	array_normal=[(i, j) for i in range(n) for j in xrange(i+1,n)]
	array_normal+=[(i, j) for i in range(n) for j in xrange(0,i-1)]
	shuffle(array_normal)
	res=[]
	i=0
	hubo_max_peaje=False
	with open(temp_file,'w') as f:
		f.write(str(n)+" "+str(cant_rutas)+"\n")
		while(i<cant_rutas):	
			valor_a=random.randint(0,max_peaje)
			if(i==cant_rutas-1)and not hubo_max_peaje:
				valor_a=max_peaje
			if(valor_a==max_peaje):
				hubo_max_peaje=True
			if(valor_a<0 or valor_a>max_peaje):
				valor_a=max_peaje/2
			f.write(str(array_normal[i][0]+1)+" "+str(array_normal[i][1]+1)+" "+str(valor_a)+str("\n"))
			i=i+1
		f.write("-1\n")
		f.close()


def armarArgumentos(ejecutable,red):
	# Esto arma los argumentos para call:
	# 	El primer elemento de la lista es el programa que se va a correr
	# 	El resto son los argumentos para este programa.
	#	O sea, si tenemos la lista l = [exec, a1, a2, a3] y hacemos call(l)
	#   es como si escribiéramos en la terminal exec a1 a2 a3 y apretáramos enter.
	#	Obs: todos tienen que ser strings.
	return [ejecutable] + map(str,red)

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
				#terminar archivo_casos
				if(len(argv)>=4):
					archivo_salida=argv[3]
				with open(archivo_salida, 'a') as f:
					for line in in_file:
						path, file_name = os.path.split(argv[2])
						test_name=line.split(" ")[0]
						test=path+"/"+test_name
						sol=line.split(" ",1)[1]	
						print "Test "+test_name+" de tamanio: "+str(red[0])+" solucion: "+str(red[1]) 
						call(ejecutable+str(" < ")+test,stdout=f,shell=True)
						test_file.close()
				f.close()
			in_file.close()
			sys.exit()
		else:
			print "error,falta el archivo de entrada"
			sys.exit()
	elif(argv[1]=="a"):
		ejecutable=ejecutable3
		if(len(argv)>=3):
			archivo_salida=argv[2]
		else:
			archivo_salida=archivo_salida3
		prueba_nro=0
		if not os.path.exists(archivo_salida):
			with open(archivo_salida, 'w') as f:
				f.write("ciudades;cantidad rutas;max peaje;solucion;tiempo;\n")
				f.close() 
		with open(archivo_salida, 'a') as f:
			for ciudades in range(10,maximo_n+1,5):	#vario la cantidad de ciudades
				for cant_rutas in range(1,max_rutas+1): #vario la cantidad de rutas
					for peaje in range(0,maximo_peaje+1): #prueba con distintos peajes
						for repes in range(max_intancias):
							generar_rutas(ciudades,cant_rutas,2**peaje)
					 		print "prueba:"+str(prueba_nro)
					 		call(ejecutable+str(" < ")+temp_file,stdout=f,shell=True)
					 		prueba_nro=prueba_nro+1
		 	f.close()
	else:
		print usage1
		sys.exit()
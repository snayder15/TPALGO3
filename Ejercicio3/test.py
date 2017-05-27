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
archivo_salida3 = "tiempo3.dat"
temp_file="temp"

maximo_n=800
intancias=300

def generar_rutas(ciudades,densidad_rutas_construidas):
	with open(temp_file,'w') as f:
		n = int (ciudades)
		completo=n*(n-1)/2
		m = int(completo*densidad_rutas_construidas)
		#creo las aristas normales
		array_normal=[(i, j) for i in range(n) for j in xrange(i+1,n)]
		array_normal+=[(i, j) for i in range(n) for j in xrange(0,i-1)]
		shuffle(array_normal)
		i=0
		f.write(str(n)+"\n")
		while(i<m):
			valor_a=random.randint(0,n**2)
			i=i+1
			f.write(str(array_normal[i][0]+1)+" "+str(array_normal[i][1]+1)+" 0 "+str(valor_a)+"\n")
		while(i<completo):
			valor_a=random.randint(0,n**2)
			i=i+1
			f.write(str(array_normal[i][0]+1)+" "+str(array_normal[i][1]+1)+" 1 "+str(valor_a)+"\n")
		f.write("-1\n")	
		f.close()

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
						args =  armarArgumentos(ejecutable, ciudades, rutas)
						print "Test "+test_name+" de tamanio: "+str(ciudades)+" solucion: "+str(sol) 
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
				f.write("ciudades;tiempo;costo;tamanio solucion;solucion;\n")
				f.close() 
		with open(archivo_salida, 'a') as f:
			for i in range(5,maximo_n,5):
				for repes in range(intancias): #cantidad de casos distintos para cada K
					red=[]
					cant_rutas=random.random()
					generar_rutas(i,cant_rutas)
			 		call(ejecutable+str(" < ")+temp_file,stdout=f,shell=True)
			 		print "prueba nro: "+str(prueba_nro)
			 		prueba_nro=prueba_nro+1
		 	f.close()
	else:
		print usage1
		sys.exit()
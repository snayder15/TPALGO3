#encoding: utf-8
import numpy as np
from numpy import *
from time import time
from random import randint,shuffle
import random
import sys
import os

from distutils.core import setup, Extension

ejecutable3 = "./tiempo"
archivo_salida3 = "tiempo1.dat"
temp_file="temp"

intancias=200
max_k=200
max_ciudades=200

def generar_rutas(ciudades,densidad_normal,densidad_premium,origen,destino,k):
	n = int (ciudades)
	m = int(n*(n-1)/2*densidad_normal)
	p = int(n*(n-1)/2*densidad_premium)
	mat = [[0 for x in xrange(n)] for y in xrange(n)]
	#creo las aristas normales
	#print "Normales: "+str(m)+" Premium:"+str(p)
	array_normal=[(i, j) for i in range(n) for j in xrange(i+1,n)]
	array_premium=[(i, j) for i in range(n) for j in xrange(i+1,n)]
	shuffle(array_normal)
	shuffle(array_premium)	
	res=[]
	with open(temp_file,'w') as f:
		f.write(str(n)+" "+str(m+p)+"\n") #escribo las ciudades y rutas
		f.write(str(origen)+" "+str(destino)+" "+str(k)+"\n")
		#escribo las premium
		for i in range(p):
			valor_a=random.randint(0,n**2)
			mat[array_normal[i][0]][array_normal[i][1]]=valor_a
			f.write(str(array_normal[i][0]+1)+" "+str(array_normal[i][1]+1)+" 1 "+str(valor_a) +"\n")
		#escribo las normales
		for i in range(m):
			posicion=mat[array_premium[i][0]][array_premium[i][1]]
			valor_a=random.randint(posicion+1,n**3+1)
			f.write(str(array_normal[i][0]+1)+" "+str(array_normal[i][1]+1)+" 0 "+str(valor_a) +"\n")
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
				#terminar archivo_casos
				if(len(argv)>=4):
					archivo_salida=argv[3]
				with open(archivo_salida, 'a') as f:
					for line in in_file:
						path, file_name = os.path.split(argv[2])
						test_name=line.split(" ")[0]
						test=path+"/"+test_name
						sol=line.split(" ",1)[1]
						print "Test "+test_name+" de tamanio: "+str(red[0])+" cantidad rutas: "+str(red[1]) 
						call(ejecutable+str(" < ")+test,stdout=f,shell=True)	
				f.close()
			in_file.close()
			sys.exit()
		else:
			print "error,falta el archivo de entrada"
			sys.exit()
	elif(argv[1]=="a"):
		ejecutable=ejecutable3
		archivo_salida=archivo_salida3
		prueba_nro=0
		if(len(argv)>=3):
			archivo_salida=argv[2]
		if not os.path.exists(archivo_salida):
			with open(archivo_salida, 'w') as f:
				f.write("ciudades;k;resultado;tiempo;\n")
				f.close() 
		with open(archivo_salida, 'a') as f:
			for ciudades in range(5,max_ciudades,5):
				for k in range(5,max_k,5):
					for repes in range(intancias): #cantidad de casos distintos para cada K
						d_normales=random.random()
						d_premium=random.random()
						orig=random.randint(1,ciudades) #defino el origen
						dest=random.randint(1,ciudades) #defino el destino
						generar_rutas(ciudades,d_normales,d_premium,orig,dest,k)
						print "prueba:"+str(prueba_nro)
				 		call(ejecutable+str(" < ")+temp_file,stdout=f,shell=True)	
				 		prueba_nro=prueba_nro+1
		 	f.close()
	else:
		print usage1
		sys.exit()
/*
 * =====================================================================================
 *
 *       Filename:  LibroCalificaciones.cpp
 *
 *    Description:  Reporte de calificaciones
 *
 *        Created:  2019-08-21
 *
 *         Author:  isaacesquivelsoto@gmail.com
 *
 * =====================================================================================
 */

#include "LibroCalificaciones.h"
#include <iomanip>
#include <iostream>




int LibroCalificaciones::obtenerNotaMinima() {
	
	int caliMin = 100;
	for (int colum = 0; colum < ESTUDIANTES; colum++)
	{
		for (int fila = 0; fila < EXAMENES; fila++)
		{
			if (calificaciones[colum][fila] < caliMin)
			{
				caliMin = calificaciones[colum][fila];
			}
		}
		
	}

	return caliMin;
}


int LibroCalificaciones::obtenerNotaMaxima() {

	int caliMax = 0;
	for (int colum = 0; colum < ESTUDIANTES; colum++) 
	{
		for (int fila = 0; fila < EXAMENES; fila++) 
		{
			if (calificaciones[colum][fila] > caliMax)
			{
				caliMax = calificaciones[colum][fila];
			}
		}
	}

	return caliMax;
}

double LibroCalificaciones::obtenerPromedio(const int est, const int colum)
{
	float nota = 0;
	
		for (int fila = 0; fila < EXAMENES; fila++)
		{
			nota = nota + calificaciones[est][fila];
		}

		nota = nota / 3;
		return nota;
}

LibroCalificaciones::LibroCalificaciones()
{
}

LibroCalificaciones::LibroCalificaciones(const std::string& nombreCurso, int arregloCalificaciones[ESTUDIANTES][EXAMENES])
{
	setNombreCurso(nombreCurso);

	for (int fila = 0; fila < ESTUDIANTES; fila++)
	{
		for (int colum = 0; colum < EXAMENES; colum++)
		{
			calificaciones[fila][colum] = arregloCalificaciones[fila][colum];
		}
	}

}

std::string LibroCalificaciones::obtenerReporteNotas()
{

		std::string reporte = "";
		std::string titulo = "\nLas siguientes son las notas del curso [" + getNombreCurso() + "]: \n\t\t\t\tExamen 1\tExamen 2\tExamen 3\tPromedio";

		for (int estudiante = 0; estudiante < ESTUDIANTES; estudiante++) {

			int est = estudiante;
			reporte = reporte + "\nEstudiante [" + std::to_string(estudiante+1) + "]\t\t\t" + std::to_string(calificaciones[estudiante][0]) + "\t\t"
				+ std::to_string(calificaciones[estudiante][1]) + "\t\t" + std::to_string(calificaciones[estudiante][2]) + "\t\t" + std::to_string(obtenerPromedio(estudiante, 3)) + "";
		}

		return titulo + reporte;
		





	
}

std::string LibroCalificaciones::obtenerReporteNotasMaxMin()
{
	int notaMax = obtenerNotaMaxima();
	int notaMin = obtenerNotaMinima();
	std::string reporteMaxMin = "";

	reporteMaxMin = reporteMaxMin + "\nLa nota minima es [" + std::to_string(notaMin) + "] \nLa nota maxima es ["
		+ std::to_string(notaMax) + "] \n";

	return reporteMaxMin;
}

std::string LibroCalificaciones::getNombreCurso()
{
	return nombreCurso;
}

void LibroCalificaciones::setNombreCurso(std::string nombre_curso)
{
	nombreCurso = nombre_curso;
}




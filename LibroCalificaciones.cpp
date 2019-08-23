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
	for (int colum = 0; colum < EXAMENES; colum++)
	{
		for (int fila = 0; fila < ESTUDIANTES; fila++)
		{
			if (calificaciones[fila][colum] < caliMin)
			{
				caliMin = calificaciones[colum][fila];
			}
		}
		
	}

	return caliMin;
}


int LibroCalificaciones::obtenerNotaMaxima() {

	int caliMax = 0;
	for (int colum = 0; colum < EXAMENES; colum++) 
	{
		for (int fila = 0; fila < ESTUDIANTES; fila++) 
		{
			if (calificaciones[fila][colum] > caliMax)
			{
				caliMax = calificaciones[colum][fila];
			}
		}
	}

	return caliMax;
}

double LibroCalificaciones::obtenerPromedio(const int[], const int fila)
{
	int nota = 0;
	
		for (int colum = 0; colum < EXAMENES; colum++)
		{
			nota = nota + calificaciones[fila][colum];
		}

		nota = nota / 3;
		return nota;
}

LibroCalificaciones::LibroCalificaciones()
{
}

LibroCalificaciones::LibroCalificaciones(const std::string& nombreCurso, int calificaciones[ESTUDIANTES][EXAMENES])
{
	setNombreCurso(nombreCurso);

	for (int colum = 0; colum < EXAMENES; colum++)
	{
		for (int fila = 0; colum < ESTUDIANTES; fila++)
		{
			calificaciones[colum][fila];
		}
	}

}

std::string LibroCalificaciones::obtenerReporteNotas()
{
	std::string reporte = "";
	std::string nombreCur = getNombreCurso();
	int columna = 0;

	reporte = reporte + "\n Las siguientes son las notas del curso [" + nombreCur + "]:"
		+ "\n\t\t\t\tExamen 1\tExamen 2\tExamen 3\tPromedio";

		for (int fila = 0; fila < ESTUDIANTES; fila++)
		{
			while (columna <= 2)
			{
				int est = fila;
				reporte = reporte + "\nEstudiante [" + std::to_string(est) + "]\t\t\t" +
					std::to_string(calificaciones[est][columna]) + "\t\t\n";
				columna++;
			}
			columna = 0;
		}


		return reporte;
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




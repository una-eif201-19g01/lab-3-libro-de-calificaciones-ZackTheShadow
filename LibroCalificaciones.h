/*
 * =====================================================================================
 *
 *       Filename:  LibroCalificaciones.h
 *
 *    Description:  Reporte de calificaciones
 *
 *        Created:  2019-08-21
 *
 *         Author:  isaacesquivelsoto@gmail.com
 *
 * =====================================================================================
 */


#ifndef CALIFICACIONES_LIBROCALIFICACIONES_H
#define CALIFICACIONES_LIBROCALIFICACIONES_H

#include <string>
#include <iostream>
#include <array>

class LibroCalificaciones {

private:

	static const int ESTUDIANTES = 10;
	static const int EXAMENES = 3;
	std::string nombreCurso = "Curso Progra I"; 
	int calificaciones [ESTUDIANTES][EXAMENES];

	//Metodos
	int obtenerNotaMinima();
	int obtenerNotaMaxima();
	double obtenerPromedio(const int[], const int);

public:

	LibroCalificaciones();
	LibroCalificaciones(const std::string& nombreCurso, int calificacionesM[ESTUDIANTES][EXAMENES]);
	std::string obtenerReporteNotas();
	std::string obtenerReporteNotasMaxMin();
	std::string getNombreCurso();
	void setNombreCurso(std::string nombreCurso);
};


#endif //CALIFICACIONES_LIBROCALIFICACIONES_H

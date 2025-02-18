// 07.01.2024


#ifndef SensorInterface_H
#define SensorInterface_H

#include <iostream>
#include <string>

class SensorInterface
{
private:
	std::string sensorType; ///< sensorun ne tur oldugunu tutan string degiskeni.

public:
	/**
	* @brief sensor degerlerini gunceller.
	* (virtual: inherite edilen siniflarda bu fonksiyonun olmasini zorunlu kilar.)
	*/
	virtual void updateSensor() = 0;

	/**
	* @brief sensor degerlerini dondurur.
	* @return hangi sensordeyse onun cagirdigi degeri dondurur.
	* (virtual: inherite edilen siniflarda bu fonksiyonun olmasini zorunlu kilar.)
	*/
	virtual std::string getSensorValue() = 0;

	/**
	* @brief sensorun tipinin dondurur.
	* @return string olarak sensor tipi doner.
	*/
	std::string getSensorType()
	{
		return sensorType;
	}
};

#endif // !SensorInterface_H


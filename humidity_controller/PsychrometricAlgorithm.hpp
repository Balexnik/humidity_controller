#ifndef PsychrometricAlgorithm_hpp
#define PsychrometricAlgorithm_hpp

#include <math.h>
#include <stdlib.h>

class PsychrometricAlgorithm
{
  public:
    static float computeHumidity(float dryT, float wetT){
      float vaporPressure = computeVaporPressure(dryT, wetT);
      float saturationPressure = computeSaturationPressure(dryT);
      return 100 * vaporPressure / saturationPressure;
    }

  private:
    static   float computeVaporPressure(float dryT, float wetT){
      const double A = 0.0007947;
      const int p = 1000;
      const double a = 0.00115;
      float saturationPressureWet = computeSaturationPressure(wetT);
      float vaporPressure = saturationPressureWet - A * p * (dryT - wetT) * (1 + a * wetT);
      return vaporPressure;
    }

    static   float computeSaturationPressure(float t){
      const double E = 6.1121;
      const double a = 17.5043;
      const double b = 241.2;
      float pressure = E * exp(abs(a * t / (b + t)));
      // Hyland and Wexler
      //t *=274.15;
      //float pressure = log(2.8365*1000/t*t-6.0280*1000/t+1.9542*10-2.7378*t/100+1.6261*t*t/100000+7.0229*t*t*t/10000000000-1.8680*t*t*t*t/10000000000000+2.7150*log(t));
      // Goff Gratch 
      //t *=274.15;
      //float pressure = log10(-7.90298*(373.16/t-1)+ 5.02808*log10(373.16/t)- 1.3816*pow(10,-7)*(pow(10,11.344*(1-t/373.16))-1)+8.1328 *pow(10,-3)*(pow(10,-3.49149*(373.16/t-1))-1)+log10(1013.246));
      return pressure;
    }
};

#endif

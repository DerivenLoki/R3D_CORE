enum ADM_ISAProperties
{
	Temperature,
	Pressure,
	Density,
	SpeedOfSound
}

// International Standard Atmosphere Model
class ADM_InternationalStandardAtmosphere
{
	// km (Kilometers)
	private static ref array<float> altitude = {0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0, 185.0, 190.0, 195.0, 200.0, 205.0, 210.0, 215.0, 220.0, 225.0, 230.0, 235.0, 240.0, 245.0, 250.0, 255.0, 260.0, 265.0, 270.0, 275.0, 280.0, 285.0, 290.0, 295.0, 300.0, 305.0, 310.0, 315.0, 320.0, 325.0, 330.0, 335.0, 340.0, 345.0, 350.0, 355.0, 360.0, 365.0, 370.0, 375.0, 380.0, 385.0, 390.0, 395.0, 400.0, 405.0, 410.0, 415.0, 420.0, 425.0, 430.0, 435.0, 440.0, 445.0, 450.0, 455.0, 460.0, 465.0, 470.0, 475.0, 480.0, 485.0, 490.0, 495.0, 500.0, 505.0, 510.0, 515.0, 520.0, 525.0, 530.0, 535.0, 540.0, 545.0, 550.0, 555.0, 560.0, 565.0, 570.0, 575.0, 580.0, 585.0, 590.0, 595.0, 600.0, 605.0, 610.0, 615.0, 620.0, 625.0, 630.0, 635.0, 640.0, 645.0, 650.0, 655.0, 660.0, 665.0, 670.0, 675.0, 680.0, 685.0, 690.0, 695.0, 700.0, 705.0, 710.0, 715.0, 720.0, 725.0, 730.0, 735.0, 740.0, 745.0, 750.0, 755.0, 760.0, 765.0, 770.0, 775.0, 780.0, 785.0, 790.0, 795.0, 800.0, 805.0, 810.0, 815.0, 820.0, 825.0, 830.0, 835.0, 840.0, 845.0, 850.0, 855.0, 860.0, 865.0, 870.0, 875.0, 880.0, 885.0, 890.0, 895.0, 900.0, 905.0, 910.0, 915.0, 920.0, 925.0, 930.0, 935.0, 940.0, 945.0, 950.0, 955.0, 960.0, 965.0, 970.0, 975.0, 980.0, 985.0, 990.0, 995.0, 1000.0};
    
	// K (Kelvin)
	private static ref array<float> temperature = {288.150, 255.676, 223.252, 216.650, 216.650, 221.552, 226.509, 236.513, 250.350, 264.164, 270.650, 260.771, 247.021, 233.292, 219.585, 208.399, 198.639, 188.893, 186.867, 188.418, 195.081, 208.835, 240.000, 300.000, 360.000, 417.231, 469.268, 516.589, 559.627, 598.776, 634.392, 666.799, 696.290, 723.132, 747.566, 769.811, 790.066, 808.511, 825.312, 840.616, 854.559, 867.264, 878.842, 889.395, 899.014, 907.785, 915.782, 923.075, 929.726, 935.794, 941.330, 946.381, 950.991, 955.198, 959.039, 962.545, 965.746, 968.670, 971.340, 973.779, 976.008, 978.044, 979.904, 981.605, 983.159, 984.580, 985.880, 987.068, 988.154, 989.148, 990.057, 990.889, 991.650, 992.347, 992.984, 993.568, 994.102, 994.591, 995.039, 995.450, 995.825, 996.170, 996.485, 996.774, 997.039, 997.282, 997.505, 997.709, 997.896, 998.067, 998.225, 998.369, 998.502, 998.623, 998.735, 998.837, 998.931, 999.017, 999.096, 999.169, 999.236, 999.297, 999.353, 999.405, 999.452, 999.496, 999.536, 999.573, 999.607, 999.638, 999.667, 999.693, 999.717, 999.740, 999.760, 999.779, 999.796, 999.812, 999.827, 999.841, 999.853, 999.864, 999.875, 999.885, 999.894, 999.902, 999.910, 999.917, 999.923, 999.929, 999.934, 999.939, 999.944, 999.948, 999.952, 999.956, 999.959, 999.962, 999.965, 999.968, 999.970, 999.973, 999.975, 999.977, 999.978, 999.980, 999.982, 999.983, 999.984, 999.985, 999.986, 999.987, 999.988, 999.989, 999.990, 999.991, 999.992, 999.992, 999.993, 999.993, 999.994, 999.994, 999.995, 999.995, 999.995, 999.996, 999.996, 999.996, 999.997, 999.997, 999.997, 999.997, 999.997, 999.998, 999.998, 999.998, 999.998, 999.998, 999.998, 999.999, 999.999, 999.999, 999.999, 999.999, 999.999, 999.999, 999.999, 999.999, 999.999, 999.999, 999.999, 999.999, 999.999, 999.999, 1000.00, 1000.00, 1000.00, 1000.00, 1000.00, 1000.00, 1000.00};
   
	// Pa (Pascals)
	private static ref array<float> pressure = {101320.000000000000000,54048.000000000000000,26500.000000000000000,12112.000000000000000,5529.300000000000182,2549.199999999999818,1197.000000000000000,574.590000000000032,287.139999999999986,149.099999999999994,79.778999999999996,42.524999999999999,21.959000000000000,10.930000000000000,5.220900000000000,2.388100000000000,1.052500000000000,0.445680000000000,0.184350000000000,0.075775000000000,0.032012000000000,0.014423000000000,0.007149300000000,0.004003700000000,0.002536600000000,0.001736000000000,0.001250300000000,0.000935690000000,0.000720290000000,0.000566900000000,0.000454220000000,0.000369290000000,0.000303940000000,0.000252770000000,0.000212100000000,0.000179360000000,0.000152720000000,0.000130810000000,0.000112650000000,0.000097489000000,0.000084736000000,0.000073943000000,0.000064757000000,0.000056902000000,0.000050150000000,0.000044321000000,0.000039270000000,0.000034879000000,0.000031051000000,0.000027701000000,0.000024762000000,0.000022176000000,0.000019894000000,0.000017875000000,0.000016084000000,0.000014494000000,0.000013078000000,0.000011815000000,0.000010686000000,0.000009676000000,0.000008770400000,0.000007957100000,0.000007225900000,0.000006567800000,0.000005974800000,0.000005440000000,0.000004957100000,0.000004520800000,0.000004126000000,0.000003768600000,0.000003444600000,0.000003150700000,0.000002883900000,0.000002641400000,0.000002420800000,0.000002220000000,0.000002037000000,0.000001870200000,0.000001717900000,0.000001578900000,0.000001451800000,0.000001335600000,0.000001229200000,0.000001131900000,0.000001042800000,0.000000961190000,0.000000886420000,0.000000817890000,0.000000755050000,0.000000697410000,0.000000644520000,0.000000595970000,0.000000551390000,0.000000510430000,0.000000472790000,0.000000438180000,0.000000406340000,0.000000377050000,0.000000350080000,0.000000325240000,0.000000302350000,0.000000281260000,0.000000261800000,0.000000243860000,0.000000227300000,0.000000212020000,0.000000197900000,0.000000184860000,0.000000172810000,0.000000161680000,0.000000151370000,0.000000141840000,0.000000133020000,0.000000124850000,0.000000117280000,0.000000110270000,0.000000103770000,0.000000097739000,0.000000092145000,0.000000086952000,0.000000082130000,0.000000077650000,0.000000073486000,0.000000069612000,0.000000066005000,0.000000062644000,0.000000059510000,0.000000056585000,0.000000053855000,0.000000051303000,0.000000048917000,0.000000046684000,0.000000044594000,0.000000042635000,0.000000040799000,0.000000039076000,0.000000037459000,0.000000035940000,0.000000034513000,0.000000033171000,0.000000031908000,0.000000030720000,0.000000029600000,0.000000028543000,0.000000027546000,0.000000026605000,0.000000025714000,0.000000024871000,0.000000024072000,0.000000023314000,0.000000022595000,0.000000021912000,0.000000021263000,0.000000020644000,0.000000020055000,0.000000019493000,0.000000018957000,0.000000018445000,0.000000017955000,0.000000017485000,0.000000017036000,0.000000016604000,0.000000016190000,0.000000015793000,0.000000015411000,0.000000015044000,0.000000014690000,0.000000014350000,0.000000014023000,0.000000013707000,0.000000013403000,0.000000013110000,0.000000012827000,0.000000012553000,0.000000012289000,0.000000012033000,0.000000011786000,0.000000011547000,0.000000011315000,0.000000011091000,0.000000010873000,0.000000010662000,0.000000010457000,0.000000010258000,0.000000010064000,0.000000009875200,0.000000009691500,0.000000009512600,0.000000009338000,0.000000009167700,0.000000009001300,0.000000008838700,0.000000008679600,0.000000008523900,0.000000008371300,0.000000008221800,0.000000008075100,0.000000007931100,0.000000007789600,0.000000007650500,0.000000007513800};
    
	// kg/m^3 (Kilograms per cubic meter)
	private static ref array<float> density = {1.225000000000000,0.736430000000000,0.413510000000000,0.194760000000000,0.088910000000000,0.040084000000000,0.018410000000000,0.008463400000000,0.003995700000000,0.001966300000000,0.001026900000000,0.000568100000000,0.000309680000000,0.000163210000000,0.000082829000000,0.000039921000000,0.000018458000000,0.000008219500000,0.000003440000000,0.000001387300000,0.000000560440000,0.000000233250000,0.000000096734000,0.000000042794000,0.000000022199000,0.000000012918000,0.000000008149400,0.000000005464700,0.000000003831300,0.000000002780500,0.000000002075200,0.000000001584800,0.000000001233600,0.000000000975260,0.000000000781550,0.000000000633820,0.000000000519400,0.000000000429520,0.000000000358070,0.000000000300640,0.000000000254070,0.000000000215960,0.000000000184560,0.000000000158490,0.000000000136710,0.000000000118390,0.000000000102900,0.000000000089757,0.000000000078550,0.000000000068954,0.000000000060706,0.000000000053587,0.000000000047420,0.000000000042058,0.000000000037382,0.000000000033294,0.000000000029710,0.000000000026560,0.000000000023783,0.000000000021331,0.000000000019159,0.000000000017232,0.000000000015519,0.000000000013994,0.000000000012634,0.000000000011419,0.000000000010333,0.000000000009361,0.000000000008489,0.000000000007705,0.000000000007001,0.000000000006367,0.000000000005795,0.000000000005279,0.000000000004813,0.000000000004391,0.000000000004009,0.000000000003663,0.000000000003348,0.000000000003063,0.000000000002803,0.000000000002566,0.000000000002351,0.000000000002154,0.000000000001975,0.000000000001812,0.000000000001663,0.000000000001527,0.000000000001402,0.000000000001288,0.000000000001184,0.000000000001089,0.000000000001002,0.000000000000922,0.000000000000849,0.000000000000782,0.000000000000721,0.000000000000664,0.000000000000613,0.000000000000565,0.000000000000521,0.000000000000481,0.000000000000445,0.000000000000411,0.000000000000379,0.000000000000351,0.000000000000324,0.000000000000300,0.000000000000278,0.000000000000257,0.000000000000238,0.000000000000221,0.000000000000205,0.000000000000190,0.000000000000176,0.000000000000164,0.000000000000152,0.000000000000141,0.000000000000131,0.000000000000122,0.000000000000114,0.000000000000106,0.000000000000099,0.000000000000092,0.000000000000086,0.000000000000080,0.000000000000075,0.000000000000070,0.000000000000065,0.000000000000061,0.000000000000057,0.000000000000053,0.000000000000050,0.000000000000047,0.000000000000044,0.000000000000041,0.000000000000039,0.000000000000037,0.000000000000035,0.000000000000033,0.000000000000031,0.000000000000029,0.000000000000027,0.000000000000026,0.000000000000024,0.000000000000023,0.000000000000022,0.000000000000021,0.000000000000020,0.000000000000019,0.000000000000018,0.000000000000017,0.000000000000016,0.000000000000015,0.000000000000015,0.000000000000014,0.000000000000013,0.000000000000013,0.000000000000012,0.000000000000012,0.000000000000011,0.000000000000011,0.000000000000010,0.000000000000010,0.000000000000010,0.000000000000009,0.000000000000009,0.000000000000009,0.000000000000008,0.000000000000008,0.000000000000008,0.000000000000008,0.000000000000007,0.000000000000007,0.000000000000007,0.000000000000007,0.000000000000006,0.000000000000006,0.000000000000006,0.000000000000006,0.000000000000006,0.000000000000006,0.000000000000005,0.000000000000005,0.000000000000005,0.000000000000005,0.000000000000005,0.000000000000005,0.000000000000005,0.000000000000005,0.000000000000004,0.000000000000004,0.000000000000004,0.000000000000004,0.000000000000004,0.000000000000004,0.000000000000004,0.000000000000004,0.000000000000004,0.000000000000004,0.000000000000004};
    
	// m/s (Meters per second)
	private static ref array<float> speed_of_sound = {340.29, 320.55, 299.53, 295.07, 295.07, 298.39, 301.71, 308.30, 317.19, 325.82, 329.80, 323.72, 315.07, 306.19, 297.06, 289.40, 282.54, 275.52, 274.04, 275.17, 280.00, 289.70, 310.56, 347.22, 380.36, 409.48, 434.27, 455.64, 474.24, 490.54, 504.92, 517.66, 528.98, 539.08, 548.11, 556.21, 563.48, 570.02, 575.91, 581.22, 586.02, 590.36, 594.29, 597.85, 601.07, 604.00, 606.65, 609.06, 611.26, 613.25, 615.06, 616.71, 618.21, 619.57, 620.82, 621.95, 622.98, 623.93, 624.79, 625.57, 626.28, 626.94, 627.53, 628.08, 628.57, 629.03, 629.44, 629.82, 630.17, 630.49, 630.78, 631.04, 631.28, 631.50, 631.71, 631.89, 632.06, 632.22, 632.36, 632.49, 632.61, 632.72, 632.82, 632.91, 633.00, 633.07, 633.14, 633.21, 633.27, 633.32, 633.37, 633.42, 633.46, 633.50, 633.53, 633.57, 633.60, 633.62, 633.65, 633.67, 633.69, 633.71, 633.73, 633.75, 633.76, 633.78, 633.79, 633.80, 633.81, 633.82, 633.83, 633.84, 633.85, 633.85, 633.86, 633.87, 633.87, 633.88, 633.88, 633.88, 633.89, 633.89, 633.90, 633.90, 633.90, 633.90, 633.91, 633.91, 633.91, 633.91, 633.91, 633.92, 633.92, 633.92, 633.92, 633.92, 633.92, 633.92, 633.92, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.93, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94, 633.94};
   
	// LookupAltitude is in meters
	static float GetValue(float lookupAltitude, ADM_ISAProperties property)
	{
		float returnValue = -999999;
		
		lookupAltitude /= 1000;
		switch(property) 
		{
			case ADM_ISAProperties.Temperature:
			{		
				returnValue = ADM_InternationalStandardAtmosphere.Interpolate(altitude, temperature, lookupAltitude, 5);
				break;
			}			
			case ADM_ISAProperties.Pressure:
			{		
				returnValue = ADM_InternationalStandardAtmosphere.Interpolate(altitude, pressure, lookupAltitude, 5);
				break;
			}			
			case ADM_ISAProperties.Density:
			{		
				returnValue = ADM_InternationalStandardAtmosphere.Interpolate(altitude, density, lookupAltitude, 5);
				break;
			}			
			case ADM_ISAProperties.SpeedOfSound:
			{		
				returnValue = ADM_InternationalStandardAtmosphere.Interpolate(altitude, speed_of_sound, lookupAltitude, 5);
				break;
			}			
			default:
			{
				Print("Unsupported ISA Property");
				break;
			}
		}
		
		return returnValue;
	}
	
	static float Interpolate(array<float> lookupArray, array<float> returnValueArray, float lookupValue, float delta)
	{
		float returnValue = -float.MAX;
		if (lookupArray.Count() != returnValueArray.Count())
		{
			Print("Lookup array and return value array are not the same length!");
			return returnValue;
		}
		
		//calculate index knowing the delta between altitude values
		int lookupArrayIndex = Math.Floor(lookupValue / delta);
		if (lookupArrayIndex < 0) 
			lookupArrayIndex = 0;
			
		//if beyond array length (extrapolating) then we just use the last slope known
		if (lookupArrayIndex >= lookupArray.Count()-1)
			lookupArrayIndex = lookupArray.Count()-2;
		
		float value1 = returnValueArray[lookupArrayIndex];
		float value2 = returnValueArray[lookupArrayIndex+1];
		returnValue = (value2 - value1) / delta * (lookupValue - lookupArray[lookupArrayIndex]) + value1;
		
		return returnValue;
	}
	
	// https://doc.comsol.com/5.5/doc/com.comsol.help.cfd/cfd_ug_fluidflow_high_mach.08.27.html
	static float GetDynamicViscosity(float lookupAltitude)
	{
		float T = ADM_InternationalStandardAtmosphere.GetValue(lookupAltitude, ADM_ISAProperties.Temperature);
		
		// Sutherlands Laws: only valid for ideal gasses
		float Su = 111; // [K]
		float T0 = 273; // [K]
		float mu0 = 1.716e-5; // [Pa*s]
		float muRatio = Math.Pow(T/T0, 3/2) * (T0+Su)/(T+Su);
		
		return muRatio * mu0;
	}
}
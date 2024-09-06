////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string_view>

/*
    Header of shared strings in the codebase, particularly with the meta
    system (for consistency, and for compiler assisted spell checking)
*/

namespace yq {
    extern const std::string_view     szA;
    extern const std::string_view     szA_Multivector;
    extern const std::string_view     szA_Quadrilateral;
    extern const std::string_view     szA_Segment;
    extern const std::string_view     szA_Tetrahedron;
    extern const std::string_view     szA_Triangle;
    extern const std::string_view     szAlpha;
    extern const std::string_view     szAlpha_Color;
    extern const std::string_view     szAlt;
    extern const std::string_view     szAltitude;
    extern const std::string_view     szAltitude_Geodetic;
    extern const std::string_view     szAltitude_LatLonAlt;
    extern const std::string_view     szAng;
    extern const std::string_view     szAngle;
    extern const std::string_view     szAngle_Cylindrical;
    extern const std::string_view     szAngle_Polar;
    extern const std::string_view     szArea;
    extern const std::string_view     szArea_Box;
    extern const std::string_view     szArea_Circle;
    extern const std::string_view     szB;
    extern const std::string_view     szB_Quadrilateral;
    extern const std::string_view     szB_Segment;
    extern const std::string_view     szB_Tetrahedron;
    extern const std::string_view     szB_Triangle;
    extern const std::string_view     szBlue;
    extern const std::string_view     szBlue_Color;
    extern const std::string_view     szBox;
    extern const std::string_view     szBox_Circle;
    extern const std::string_view     szC;
    extern const std::string_view     szC_Quadrilateral;
    extern const std::string_view     szC_Tetrahedron;
    extern const std::string_view     szC_Triangle;
    extern const std::string_view     szCenter;
    extern const std::string_view     szCenter_Box;
    extern const std::string_view     szCenter_Circle;
    extern const std::string_view     szCenter_Sphere;
    extern const std::string_view     szCir;
    extern const std::string_view     szCirc;
    extern const std::string_view     szCircumcircle;
    extern const std::string_view     szCircumcircle_Box;
    extern const std::string_view     szCircumference;
    extern const std::string_view     szCircumference_Circle;
    extern const std::string_view     szCnt;
    extern const std::string_view     szCorner;
    extern const std::string_view     szCount;
    extern const std::string_view     szCount_Count;
    extern const std::string_view     szCount_Polygon;
    extern const std::string_view     szCount_Polyline;
    extern const std::string_view     szContains;
    extern const std::string_view     szContains_Box_Box;
    extern const std::string_view     szContains_Box_Pt;
    extern const std::string_view     szCtr;
    extern const std::string_view     szCurrent;
    extern const std::string_view     szD;
    extern const std::string_view     szD_Quadrilateral;
    extern const std::string_view     szD_Tetrahedron;
    extern const std::string_view     szDay;
    extern const std::string_view     szDays;
    extern const std::string_view     szDen;
    extern const std::string_view     szDenominator;
    extern const std::string_view     szDenominator_Fraction;
    extern const std::string_view     szDepth;
    extern const std::string_view     szDia;
    extern const std::string_view     szDiameter;
    extern const std::string_view     szDiameter_Circle;
    extern const std::string_view     szDim;
    extern const std::string_view     szDimension;
    extern const std::string_view     szDimension_Box;
    extern const std::string_view     szDir;
    extern const std::string_view     szDirection;
    extern const std::string_view     szDirection_Normal;
    extern const std::string_view     szDirection_Ray;
    extern const std::string_view     szDist;
    extern const std::string_view     szDistance;
    extern const std::string_view     szDistance_Plane;
    extern const std::string_view     szDuration;
    extern const std::string_view     szE;
    extern const std::string_view     szEclipses;
    extern const std::string_view     szEclipses_Box_Box;
    extern const std::string_view     szEclipses_Box_Circle;
    extern const std::string_view     szEclipses_Box_Pt;
    extern const std::string_view     szF;
    extern const std::string_view     szG;
    extern const std::string_view     szGreen;
    extern const std::string_view     szGreen_Color;
    extern const std::string_view     szH;
    extern const std::string_view     szHeight;
    extern const std::string_view     szHi;
    extern const std::string_view     szHigh;
    extern const std::string_view     szHigh_Box;
    extern const std::string_view     szHigh_Range;
    extern const std::string_view     szHour;
    extern const std::string_view     szHours;
    extern const std::string_view     szHue;
    extern const std::string_view     szHue_Color;
    extern const std::string_view     szHypervolume;
    extern const std::string_view     szHypervolume_Box4;
    extern const std::string_view     szHypervolume_Sphere4;
    extern const std::string_view     szHVol;
    extern const std::string_view     szI;
    extern const std::string_view     szI_Coord;
    extern const std::string_view     szIm;
    extern const std::string_view     szImag;
    extern const std::string_view     szImaginary;
    extern const std::string_view     szImaginary_Complex;
    extern const std::string_view     szIncircle;
    extern const std::string_view     szIncircle_Box;
    extern const std::string_view     szIntensity;
    extern const std::string_view     szJ;
    extern const std::string_view     szJ_Coord;
    extern const std::string_view     szK;
    extern const std::string_view     szK_Coord;
    extern const std::string_view     szL;
    extern const std::string_view     szL_Coord;
    extern const std::string_view     szLat;
    extern const std::string_view     szLatitude;
    extern const std::string_view     szLatitude_Geodetic;
    extern const std::string_view     szLatitude_LatLon;
    extern const std::string_view     szLatitude_LatLonAlt;
    extern const std::string_view     szLen;
    extern const std::string_view     szLen²;
    extern const std::string_view     szLength;
    extern const std::string_view     szLength_Vector;
    extern const std::string_view     szLength²;
    extern const std::string_view     szLength²_Vector;
    extern const std::string_view     szLightness;
    extern const std::string_view     szLightness_Color;
    extern const std::string_view     szLo;
    extern const std::string_view     szLon;
    extern const std::string_view     szLongitude;
    extern const std::string_view     szLongitude_Geodetic;
    extern const std::string_view     szLongitude_LatLon;
    extern const std::string_view     szLongitude_LatLonAlt;
    extern const std::string_view     szLow;
    extern const std::string_view     szLow_Box;
    extern const std::string_view     szLow_Range;
    extern const std::string_view     szM;
    extern const std::string_view     szM_Coord;
    extern const std::string_view     szMag;
    extern const std::string_view     szMagnitude;
    extern const std::string_view     szMagnitude_Complex;
    extern const std::string_view     szMass;
    extern const std::string_view     szMatter;
    extern const std::string_view     szMin;
    extern const std::string_view     szMinute;
    extern const std::string_view     szMinutes;
    extern const std::string_view     szMonth;
    extern const std::string_view     szMonths;
    extern const std::string_view     szN;
    extern const std::string_view     szN_Coord;
    extern const std::string_view     szNE;
    extern const std::string_view     szNormal;
    extern const std::string_view     szNormal_Plane;
    extern const std::string_view     szNortheast;
    extern const std::string_view     szNortheast_Box;
    extern const std::string_view     szNorthwest;
    extern const std::string_view     szNorthwest_Box;
    extern const std::string_view     szNum;
    extern const std::string_view     szNumerator;
    extern const std::string_view     szNumerator_Fraction;
    extern const std::string_view     szNW;
    extern const std::string_view     szO;
    extern const std::string_view     szOri;
    extern const std::string_view     szOrientation;
    extern const std::string_view     szOrientation_Pose;
    extern const std::string_view     szOverlaps;
    extern const std::string_view     szOverlaps_Box_Box;
    extern const std::string_view     szP;
    extern const std::string_view     szPercent;
    extern const std::string_view     szPeri;
    extern const std::string_view     szPerimeter;
    extern const std::string_view     szPerimeter_Box;
    extern const std::string_view     szPerimeter_Circle;
    extern const std::string_view     szPoint;
    extern const std::string_view     szPoint_Ray;
    extern const std::string_view     szPos;
    extern const std::string_view     szPosition;
    extern const std::string_view     szPosition_Pose;
    extern const std::string_view     szPosition_Rectangle;
    extern const std::string_view     szProject;
    extern const std::string_view     szProject_Box;
    extern const std::string_view     szPt;
    extern const std::string_view     szQ;
    extern const std::string_view     szR;
    extern const std::string_view     szRad;
    extern const std::string_view     szRadius;
    extern const std::string_view     szRadius_Circle;
    extern const std::string_view     szRadius_Cylindrical;
    extern const std::string_view     szRadius_Polar;
    extern const std::string_view     szRadius_Sphere;
    extern const std::string_view     szRe;
    extern const std::string_view     szReal;
    extern const std::string_view     szReal_Complex;
    extern const std::string_view     szRed;
    extern const std::string_view     szRed_Color;
    extern const std::string_view     szS;
    extern const std::string_view     szSArea;
    extern const std::string_view     szSaturation;
    extern const std::string_view     szSaturation_Color;
    extern const std::string_view     szSE;
    extern const std::string_view     szSec;
    extern const std::string_view     szSecond;
    extern const std::string_view     szSeconds;
    extern const std::string_view     szSize;
    extern const std::string_view     szSize_Box;
    extern const std::string_view     szSize_Rectangle;
    extern const std::string_view     szSoutheast;
    extern const std::string_view     szSoutheast_Box;
    extern const std::string_view     szSouthwest;
    extern const std::string_view     szSouthwest_Box;
    extern const std::string_view     szSurfaceArea;
    extern const std::string_view     szSurfaceArea_Box3;
    extern const std::string_view     szSW;
    extern const std::string_view     szT;
    extern const std::string_view     szTemperature;
    extern const std::string_view     szTime;
    extern const std::string_view     szU;
    extern const std::string_view     szUnproject;
    extern const std::string_view     szUnproject_Box;
    extern const std::string_view     szV;
    extern const std::string_view     szValue;
    extern const std::string_view     szValue_Color;
    extern const std::string_view     szValid;
    extern const std::string_view     szValid_Box;
    extern const std::string_view     szValid_Circle;
    extern const std::string_view     szVol;
    extern const std::string_view     szVolume;
    extern const std::string_view     szVolume_Box;
    extern const std::string_view     szVolume_Sphere;
    extern const std::string_view     szW;
    extern const std::string_view     szW_Box;
    extern const std::string_view     szW_Multivector;
    extern const std::string_view     szW_Quaternion;
    extern const std::string_view     szW_Size;
    extern const std::string_view     szW_Vector;
    extern const std::string_view     szWidth;
    extern const std::string_view     szWW;
    extern const std::string_view     szWW_Tensor;
    extern const std::string_view     szWX;
    extern const std::string_view     szWX_Bivector;
    extern const std::string_view     szWX_Multivector;
    extern const std::string_view     szWX_Tensor;
    extern const std::string_view     szWXY;
    extern const std::string_view     szWXY_Multivector;
    extern const std::string_view     szWXY_Trivector;
    extern const std::string_view     szWY;
    extern const std::string_view     szWY_Tensor;
    extern const std::string_view     szWZ;
    extern const std::string_view     szWZ_Tensor;
    extern const std::string_view     szX;
    extern const std::string_view     szX_Box;
    extern const std::string_view     szX_Multivector;
    extern const std::string_view     szX_Quaternion;
    extern const std::string_view     szX_Size;
    extern const std::string_view     szX_Vector;
    extern const std::string_view     szXW;
    extern const std::string_view     szXW_Tensor;
    extern const std::string_view     szXX;
    extern const std::string_view     szXX_Tensor;
    extern const std::string_view     szXY;
    extern const std::string_view     szXY_Bivector;
    extern const std::string_view     szXY_Multivector;
    extern const std::string_view     szXY_Tensor;
    extern const std::string_view     szXYZ;
    extern const std::string_view     szXYZ_Multivector;
    extern const std::string_view     szXYZ_Trivector;
    extern const std::string_view     szXYZW;
    extern const std::string_view     szXYZW_Multivector;
    extern const std::string_view     szXYZW_Quadvector;
    extern const std::string_view     szXZ;
    extern const std::string_view     szXZ_Bivector;
    extern const std::string_view     szXZ_Multivector;
    extern const std::string_view     szXZ_Tensor;
    extern const std::string_view     szY;
    extern const std::string_view     szY_Box;
    extern const std::string_view     szY_Multivector;
    extern const std::string_view     szY_Quaternion;
    extern const std::string_view     szY_Size;
    extern const std::string_view     szY_Vector;
    extern const std::string_view     szYear;
    extern const std::string_view     szYears;
    extern const std::string_view     szYW;
    extern const std::string_view     szYW_Bivector;
    extern const std::string_view     szYW_Multivector;
    extern const std::string_view     szYW_Tensor;
    extern const std::string_view     szYX;
    extern const std::string_view     szYX_Bivector;
    extern const std::string_view     szYX_Multivector;
    extern const std::string_view     szYX_Tensor;
    extern const std::string_view     szYY;
    extern const std::string_view     szYY_Tensor;
    extern const std::string_view     szYZ;
    extern const std::string_view     szYZ_Bivector;
    extern const std::string_view     szYZ_Multivector;
    extern const std::string_view     szYZ_Tensor;
    extern const std::string_view     szYZW;
    extern const std::string_view     szYZW_Multivector;
    extern const std::string_view     szYZW_Trivector;
    extern const std::string_view     szZ;
    extern const std::string_view     szZ_Box;
    extern const std::string_view     szZ_Cylindrical;
    extern const std::string_view     szZ_Multivector;
    extern const std::string_view     szZ_Quaternion;
    extern const std::string_view     szZ_Size;
    extern const std::string_view     szZ_Vector;
    extern const std::string_view     szZ_Vector2;
    extern const std::string_view     szZW;
    extern const std::string_view     szZW_Bivector;
    extern const std::string_view     szZW_Multivector;
    extern const std::string_view     szZW_Tensor;
    extern const std::string_view     szZWX;
    extern const std::string_view     szZWX_Multivector;
    extern const std::string_view     szZWX_Trivector;
    extern const std::string_view     szZX;
    extern const std::string_view     szZX_Bivector;
    extern const std::string_view     szZX_Multivector;
    extern const std::string_view     szZX_Tensor;
    extern const std::string_view     szZY;
    extern const std::string_view     szZY_Tensor;
    extern const std::string_view     szZZ;
    extern const std::string_view     szZZ_Tensor;
}

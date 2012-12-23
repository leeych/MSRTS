#ifndef MUTILITY_H
#define MUTILITY_H

#include <QString>

#ifndef byte
typedef unsigned char  byte;
#endif

#ifndef BTime
/** Define the binary time struct
 *
 */
typedef struct BTimeTag
{
    short     year;
    byte      month;
    byte      day;
    short     jday;     /*day in current year*/
    byte      hour;
    byte      minute;
    byte      second;
    byte      padding;  /*not used, always 0*/
    short     tenth_ms; /*count in tenth milli-seconds*/
}BTime;

#endif

#ifndef UN_INITID_INT
#define    UN_INITID_INT                     (-1234567)
#endif

#ifndef UN_INITID_FLOAT
#define    UN_INITID_FLOAT                   (-1234567.0)
#endif

/**  Define of the point in wgs coordinate
 */
#ifndef WgsPoint
typedef struct WgsPointTag
{
    float   latitude;
    float   longitude;
    float   elevation;   /* unit in meter,
                            positive value means above sea level
                            negative value means below sea leavel
                         */
    WgsPointTag(float lat, float lon, float elev):
        latitude(lat),
        longitude(lon),
        elevation(elev)
    {
    }

    WgsPointTag():
    latitude(UN_INITID_FLOAT),
        longitude(UN_INITID_FLOAT),
        elevation(UN_INITID_FLOAT)
    {
    }

}WgsPoint;
#endif

/**  Define of the point in cartesian coordinate
 *   The unit is meter
 */
#ifndef DesPoint
typedef struct DesPointTag
{
    float x; /* northing location */
    float y; /* easting location */
    float z; /* deep location */
    DesPointTag(float dx, float dy, float dz):
        x(dx),
        y(dy),
        z(dz)
    {

    }

    DesPointTag():
    x(UN_INITID_FLOAT),
        y(UN_INITID_FLOAT),
        z(UN_INITID_FLOAT)
    {

    }
}DesPoint;
#endif

/**  Define of the point in utm coordinate
 */
#ifndef UtmPoint
typedef struct UtmPointTag
{
    float x;
    float y;
    float elevation;
    UtmPointTag(float ux, float uy, float elev):
        x(ux),
        y(uy),
        elevation(elev)
    {

    }

    UtmPointTag():
    x(UN_INITID_FLOAT),
        y(UN_INITID_FLOAT),
        elevation(UN_INITID_FLOAT)
    {

    }
}UtmPoint;
#endif

/** Define the Point struct used in system
 *
 */
#ifndef Point
typedef struct PointTag
{
    WgsPoint     wgs_point;
    DesPoint     des_point;
    UtmPoint     utm_point;
}Point;
#endif

extern void getMainDir(QString& strDir);
extern void getImageDir(QString& strImageDir);
extern void getCssDir(QString& strCssDir);
extern void getCurIconDir(QString& strCurIconDir);
extern void getCurseIconDir(QString& strCurseIconDir);
extern void getClickIconDir(QString& strClickIconDir);
extern void GetPolarIconDir(QString& strDir);//by mayue
extern QByteArray fetchQrc(const QString &fileName);
#endif // UTILITY_H

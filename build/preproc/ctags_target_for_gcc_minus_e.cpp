# 1 "/Users/kabukiyuutarou/project/arduino-test/arduino-test.ino"
//www.elegoo.com
//2018.10.25


# 6 "/Users/kabukiyuutarou/project/arduino-test/arduino-test.ino" 2


static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, 0 );



/*

 * Initialize the serial port.

 */
# 16 "/Users/kabukiyuutarou/project/arduino-test/arduino-test.ino"
void setup( )
{
  Serial.begin( 9600);
}



/*

 * Poll for a measurement, keeping the state machine alive.  Returns

 * true if a measurement is available.

 */
# 27 "/Users/kabukiyuutarou/project/arduino-test/arduino-test.ino"
static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 10ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}



/*

 * Main program loop.

 */
# 49 "/Users/kabukiyuutarou/project/arduino-test/arduino-test.ino"
void loop( )
{
  float temperature;
  float humidity;

  /* Measure temperature and humidity.  If the functions returns

     true, then a measurement is available. */
# 56 "/Users/kabukiyuutarou/project/arduino-test/arduino-test.ino"
  if( measure_environment( &temperature, &humidity ) == true )
  {
    Serial.print( "T = " );
    Serial.print( temperature, 1 );
    Serial.print( " deg. C, H = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
  }
}

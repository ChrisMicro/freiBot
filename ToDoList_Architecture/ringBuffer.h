
#ifdef __cplusplus
extern "C"
{
#endif

#ifndef __RINBBUFFER__
  #define __RINBBUFFER__
  #include <stdint.h>

		typedef struct
		{
			uint32_t runTime;
			void (*DoFunction)(int16_t,int16_t);
			int16_t var1;
			int16_t var2;
		} ToDo_t;

	  typedef ToDo_t data_t;

	  typedef struct
	  {
		uint16_t bufferSize;
		data_t *data;
		uint16_t fillSize;
		uint16_t writePosition;
	  } ringBuffer_t;


	  void ringBufferInit( ringBuffer_t * buf, data_t *dataArray, uint16_t bufferSize  );
	  void ringBufferAdd( ringBuffer_t * buf, data_t value);
	  data_t ringBufReadValueAtPosition( ringBuffer_t * buf, uint16_t index);
	  data_t ringBufGetValue( ringBuffer_t * buf);
	  uint16_t ringBufGetFillSize( ringBuffer_t * buf);
	  uint8_t ringBufferIsEmpty( ringBuffer_t * buf);
	  void ringBufAddInFront(ringBuffer_t * buf,ToDo_t list[], uint16_t length);

  #endif // __RINBBUFFER__

#ifdef __cplusplus
}
#endif

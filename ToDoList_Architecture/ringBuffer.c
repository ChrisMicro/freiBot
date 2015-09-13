/*
 ============================================================================
 Name        : ringBuffer.c
 Author      : chris
 Version     :
 Copyright   : GPL lizense 3
               ( chris (at) roboterclub-freiburg.de )
 Description : This ringBuffer overwrites circular the old values if
               the bufferSize is overflow.
               It is not a FIFO.
 ============================================================================
 */

#include "ringBuffer.h"

void ringBufferInit( ringBuffer_t * buf, data_t *dataArray, uint16_t bufferSize  )
{
  buf->bufferSize    = bufferSize;
  buf->data          = dataArray;
  buf->writePosition = 0;
  buf->fillSize      = 0;
}

void ringBufferAdd( ringBuffer_t * buf, data_t value)
{
  buf->data[buf->writePosition] = value;

  buf->writePosition++;
  // wrap arround if overflow
  if ( buf->writePosition >= buf->bufferSize ) buf->writePosition = 0;

  buf->fillSize++;
  // if buffer is full, do no longer increase fillSize
  if(buf->fillSize >= buf->bufferSize) buf->fillSize = buf->bufferSize;

}

// read a value from position n relative to the current write position
data_t ringBufReadValueAtPosition( ringBuffer_t * buf, uint16_t index)
{
  int32_t pos;

  pos = (int32_t)buf->writePosition + index - buf->fillSize;

  // if wrap arround
  if ( pos < 0 ) pos += buf->bufferSize;

  return buf->data[pos];
}

// get a value from the buffer and reduce the fill size by 1
data_t ringBufGetValue( ringBuffer_t * buf)
{
  int32_t pos;

  pos = (int32_t)buf->writePosition - buf->fillSize;

  // if wrap arround
  if ( pos < 0 ) pos += buf->bufferSize;
  // decrease fill size
  if(buf->bufferSize>0) buf->fillSize--;

  return buf->data[pos];
}

// add the ToDo list elements to the beginning of the ringbuffer
void ringBufAddInFront(ringBuffer_t * buf,ToDo_t list[], uint16_t length)
{
	uint16_t n;
	int32_t pos,oldPos;

	oldPos=(int32_t)buf->writePosition ;
	pos = oldPos - buf->fillSize - length;

	// if wrap arround
	if ( pos < 0 ) pos += buf->bufferSize;

	// set write position to start
	buf->writePosition=pos;

	for(n=0;n<length;n++)
	{
		ringBufferAdd(buf,list[n]);
	}

	// restore old write postion at the end
	buf->writePosition=oldPos;
}

uint16_t ringBufGetFillSize( ringBuffer_t * buf)
{
  return buf->fillSize;
}

uint8_t ringBufferIsEmpty( ringBuffer_t * buf)
{
  return (ringBufGetFillSize(buf)==0);
}


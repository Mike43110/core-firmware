/******************************************************************* 
 * Header file generated by Protoc for Embedded C.                 *
 * Version 1.0M4 (2013-03-31)                                      *
 *                                                                 *
 * Copyright (c) 2009-2013                                         *
 * Technische Universitaet Muenchen                                *
 * http://www4.in.tum.de/                                          *
 *                                                                 *
 * Source : Chunk.proto
 *                                                                 *
 * Do not edit.                                                    *
 *******************************************************************/

#ifndef _Chunk_H
#define _Chunk_H

#ifdef __cplusplus
  extern "C" {
#endif

#define MAX_BYTES_LENGTH 32

/*******************************************************************
 * Message: Chunk.proto, line 5
 *******************************************************************/

/* Maximum size of a serialized Chunk-message, useful for buffer allocation. */
#define MAX_Chunk_SIZE 79

/* Structure that holds a deserialized Chunk-message. */
struct Chunk {
    int _crc_len;
    char _crc[MAX_BYTES_LENGTH];
    unsigned long _length;
    int _data_len;
    char _data[MAX_BYTES_LENGTH];
};

/*
 * Serialize a Person-message into the given buffer at offset and return
 * new offset for optional next message.
 */
int Chunk_write_delimited_to(struct Chunk *_Chunk, void *_buffer, int offset);

/*
 * Serialize a Person-message together with its tag into the given buffer 
 * at offset and return new offset for optional next message.
 * Is useful if a Person-message is embedded in another message.
 */
int Chunk_write_with_tag(struct Chunk *_Chunk, void *_buffer, int offset, int tag);

/*
 * Deserialize a Person-message from the given buffer at offset and return
 * new offset for optional next message.
 *
 * Note: All fields in _Person will be reset to 0 before _buffer is interpreted.
 */
int Chunk_read_delimited_from(void *_buffer, struct Chunk *_Chunk, int offset);



#ifdef __cplusplus
  }
#endif

#endif


/******************************************************************* 
 * C file generated by Protoc for Embedded C.                      *
 * Version 1.0M4 (2013-03-31)                                      *
 *                                                                 *
 * Copyright (c) 2009-2013                                         *
 * Technische Universitaet Muenchen                                *
 * http://www4.in.tum.de/                                          *
 *                                                                 *
 * Source : update_begin.proto
 *                                                                 *
 * Do not edit.                                                    *
 *******************************************************************/
 
#include "Update_begin.h"

/*******************************************************************
 * Message: Update_begin.proto, line 3
 *******************************************************************/

void UpdateBegin_clear(struct UpdateBegin *_UpdateBegin) {
	_memset(_UpdateBegin, 0, sizeof(struct UpdateBegin));
}

void UpdateBegin_init_optional_attributes(struct UpdateBegin *_UpdateBegin) {
	_UpdateBegin->_counter = 0;
	
}

int UpdateBegin_is_default_message(struct UpdateBegin *_UpdateBegin) {
    return _UpdateBegin->_counter == 0
    ;
}

int UpdateBegin_write(struct UpdateBegin *_UpdateBegin, void *_buffer, int offset) {
	/* Write content of each message element.*/
	/* Write the optional attribute only if it is different than the default value. */
	if(_UpdateBegin->_counter != 0) {
		offset = write_raw_varint32((1<<3)+0, _buffer, offset);
	    offset = write_raw_varint32(_UpdateBegin->_counter, _buffer, offset);
	}
	
	return offset;
}

int UpdateBegin_write_with_tag(struct UpdateBegin *_UpdateBegin, void *_buffer, int offset, int tag) {
	/* Write tag.*/
	offset = write_raw_varint32((tag<<3)+2, _buffer, offset);
	/* Write content.*/
	offset = UpdateBegin_write_delimited_to(_UpdateBegin, _buffer, offset);
	
	return offset;
}

int UpdateBegin_write_delimited_to(struct UpdateBegin *_UpdateBegin, void *_buffer, int offset) {
	int i, shift, new_offset, size;
	
	new_offset = UpdateBegin_write(_UpdateBegin, _buffer, offset);
	size = new_offset - offset;
	shift = (size > 127) ? 2 : 1;
	for (i = new_offset - 1; i >= offset; -- i)
	    *((char *)_buffer + i + shift) = *((char *)_buffer + i);
	
	write_raw_varint32((unsigned long) size, _buffer, offset);         
	    
	return new_offset + shift;
}

int UpdateBegin_read(void *_buffer, struct UpdateBegin *_UpdateBegin, int offset, int limit) {
	unsigned int i = 0;
	unsigned long long value = i;
	unsigned long tag = value;
	
	/* Reset all attributes to 0 in advance. */
	UpdateBegin_clear(_UpdateBegin);
	/* Assign the optional attributes. */
	UpdateBegin_init_optional_attributes(_UpdateBegin);
	
	/* Read/interpret all attributes from buffer offset until upper limit is reached. */
	while(offset < limit) {
	    offset = read_raw_varint32(&tag, _buffer, offset);
		tag = tag>>3;
	    switch(tag){
	        /* tag of: _UpdateBegin._counter */
	        case 1 :
	        	offset = read_raw_varint32(&tag, _buffer, offset);
	        	_UpdateBegin->_counter = tag;
	        	break;
	    }
	}
	
	return offset;
}

int UpdateBegin_read_delimited_from(void *_buffer, struct UpdateBegin *_UpdateBegin, int offset) {
	unsigned long size;
	
	offset = read_raw_varint32(&size, _buffer, offset);
	UpdateBegin_read(_buffer, _UpdateBegin, offset, size + offset);
	
	return offset + size;
}

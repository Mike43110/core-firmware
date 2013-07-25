/******************************************************************* 
 * C file generated by Protoc for Embedded C.                      *
 * Version 1.0M4 (2013-03-31)                                      *
 *                                                                 *
 * Copyright (c) 2009-2013                                         *
 * Technische Universitaet Muenchen                                *
 * http://www4.in.tum.de/                                          *
 *                                                                 *
 * Source : variable_request.proto
 *                                                                 *
 * Do not edit.                                                    *
 *******************************************************************/
 
#include "Variable_request.h"

/*******************************************************************
 * Message: Variable_request.proto, line 3
 *******************************************************************/

void VariableRequest_clear(struct VariableRequest *_VariableRequest) {
	_memset(_VariableRequest, 0, sizeof(struct VariableRequest));
}

void VariableRequest_init_optional_attributes(struct VariableRequest *_VariableRequest) {
	_VariableRequest->_counter = 0;
	
}

int VariableRequest_is_default_message(struct VariableRequest *_VariableRequest) {
    return _VariableRequest->_counter == 0
    ;
}

int VariableRequest_write(struct VariableRequest *_VariableRequest, void *_buffer, int offset) {
	/* Write content of each message element.*/
	/* Write the optional attribute only if it is different than the default value. */
	if(_VariableRequest->_counter != 0) {
		offset = write_raw_varint32((1<<3)+0, _buffer, offset);
	    offset = write_raw_varint32(_VariableRequest->_counter, _buffer, offset);
	}
	
	return offset;
}

int VariableRequest_write_with_tag(struct VariableRequest *_VariableRequest, void *_buffer, int offset, int tag) {
	/* Write tag.*/
	offset = write_raw_varint32((tag<<3)+2, _buffer, offset);
	/* Write content.*/
	offset = VariableRequest_write_delimited_to(_VariableRequest, _buffer, offset);
	
	return offset;
}

int VariableRequest_write_delimited_to(struct VariableRequest *_VariableRequest, void *_buffer, int offset) {
	int i, shift, new_offset, size;
	
	new_offset = VariableRequest_write(_VariableRequest, _buffer, offset);
	size = new_offset - offset;
	shift = (size > 127) ? 2 : 1;
	for (i = new_offset - 1; i >= offset; -- i)
	    *((char *)_buffer + i + shift) = *((char *)_buffer + i);
	
	write_raw_varint32((unsigned long) size, _buffer, offset);         
	    
	return new_offset + shift;
}

int VariableRequest_read(void *_buffer, struct VariableRequest *_VariableRequest, int offset, int limit) {
	unsigned int i = 0;
	unsigned long long value = i;
	unsigned long tag = value;
	
	/* Reset all attributes to 0 in advance. */
	VariableRequest_clear(_VariableRequest);
	/* Assign the optional attributes. */
	VariableRequest_init_optional_attributes(_VariableRequest);
	
	/* Read/interpret all attributes from buffer offset until upper limit is reached. */
	while(offset < limit) {
	    offset = read_raw_varint32(&tag, _buffer, offset);
		tag = tag>>3;
	    switch(tag){
	        /* tag of: _VariableRequest._counter */
	        case 1 :
	        	offset = read_raw_varint32(&tag, _buffer, offset);
	        	_VariableRequest->_counter = tag;
	        	break;
	    }
	}
	
	return offset;
}

int VariableRequest_read_delimited_from(void *_buffer, struct VariableRequest *_VariableRequest, int offset) {
	unsigned long size;
	
	offset = read_raw_varint32(&size, _buffer, offset);
	VariableRequest_read(_buffer, _VariableRequest, offset, size + offset);
	
	return offset + size;
}

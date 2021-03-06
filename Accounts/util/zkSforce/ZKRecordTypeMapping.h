// Copyright (c) 2010 Ron Hess
//
// Permission is hereby granted, free of charge, to any person obtaining a 
// copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included 
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
// THE SOFTWARE.
//

#import "ZKXmlDeserializer.h"
/*
 <element name="available" type="xsd:boolean"/>
 <element name="defaultRecordTypeMapping" type="xsd:boolean"/>
 <element name="layoutId" type="tns:ID"/>
 <element name="name" type="xsd:string"/>
 <element name="picklistsForRecordType" type="tns:PicklistForRecordType" nillable="true" minOccurs="0" maxOccurs="unbounded"/>
 <element name="recordTypeId" type="tns:ID" nillable="true"/>
 */
@interface ZKRecordTypeMapping: ZKXmlDeserializer {
	NSArray *picklistsForRecordType;
}

- (BOOL) available;
- (BOOL) defaultRecordTypeMapping; 
- (NSString *) layoutId;
- (NSString *) name;
- (NSArray *) picklistsForRecordType;
- (NSString *) recordTypeId;

@end

//
//  OlapicCurationMediaEntity.h
//  OlapicSDKFramework
//  https://github.com/Olapic/Olapic-SDK-iOS
//
//  Created by The Olapic Team on 7/4/14.
//  Copyright (c) 2014 Olapic, Inc. All rights reserved.
//  https://olapic.com
//
//  The MIT License (MIT)
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to
//  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//  the Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import "OlapicMediaEntity.h"
@class OlapicStreamEntity;
@class OlapicMediaStatus;
/**
 *  Represents Olapic Curation Media Entity in the SDK
 *  @see OlapicMediaEntity
 */
@interface OlapicCurationMediaEntity : OlapicMediaEntity
/**
 *  Link the media object a specific stream
 *
 *  @param stream  The stream to link
 *  @param success A callback block for when the connection is successfully done. The result is a list with the requested links, its information and if the operations were completed
 *  @param failure A callback block in case the operation fails
 *  @since v1.0
 */
-(void)linkStream:(OlapicStreamEntity *)stream onSuccess:(void (^)(NSArray *result))success onFailure:(void (^)(NSError *error))failure;
/**
 *  Link the media object to a list of streams
 *
 *  @param streams A list of streams to link
 *  @param success A callback block for when the connection is successfully done. The result is a list with the requested links, its information and if the operations were completed
 *  @param failure A callback block in case the operation fails
 *  @since v1.0
 */
-(void)linkStreams:(NSArray *)streams onSuccess:(void (^)(NSArray *result))success onFailure:(void (^)(NSError *error))failure;
/**
 *  Remove a linked stream from the media object
 *
 *  @param stream  The stream to remove
 *  @param success A callback block for when the connection is successfully done. The result is a list with the requested unlinks, its information and if the operations were completed
 *  @param failure A callback block in case the operation fails
 *  @since v1.0
 */
-(void)unlinkStream:(OlapicStreamEntity *)stream onSuccess:(void (^)(NSArray *result))success onFailure:(void (^)(NSError *error))failure;
/**
 *  Remove a list of linked streams from the media object
 *
 *  @param streams A list of streams to remove
 *  @param success A callback block for when the connection is successfully done. The result is a list with the requested unlinks, its information and if the operations were completed
 *  @param failure A callback block in case the operation fails
 *  @since v1.0
 */
-(void)unlinkStreams:(NSArray *)streams onSuccess:(void (^)(NSArray *result))success onFailure:(void (^)(NSError *error))failure;
/**
 *  Add or change the status of the media object
 *
 *  @param status  The new status
 *  @param success A callback block for when the status is successfully changed
 *  @param failure A callback block in case the operation fails
 *  @since v1.0
 */
-(void)setStatus:(OlapicMediaStatus *)status onSuccess:(void (^)(NSDictionary *result))success onFailure:(void (^)(NSError *error))failure;

@end
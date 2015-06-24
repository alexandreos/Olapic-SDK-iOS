//
//  OlapicCurationQueue.h
//  OlapicSDKFramework
//  https://github.com/Olapic/Olapic-SDK-iOS
//
//  Created by The Olapic Team on 8/6/14.
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

#import <Foundation/Foundation.h>

@class OlapicCurationMediaEntity;
@class OlapicMediaStatus;
@class OlapicBulkRequest;
@protocol OlapicCurationQueueDelegate;
/**
 *  Manage a queue of media status association
 */
@interface OlapicCurationQueue : NSObject{
    /**
     *  The delegate object for the queue protocol
     */
    id <OlapicCurationQueueDelegate>__weak delegate;
    /**
     *  How many items the queue will wait before sending a request
     */
    NSInteger itemsToProcess;
}
/**
 *  The delegate object for the queue protocol
 */
@property (nonatomic,weak) id <OlapicCurationQueueDelegate>__weak delegate;
/**
 *  How many items the queue will wait before sending a request
 */
@property (nonatomic) NSInteger itemsToProcess;
/**
 *  Class constructor
 *
 *  @param identifier A unique identifier that will be used to save the queue in the user defaults
 *
 *  @return An instance of this object (OlapicCurationQueue)
 *  @since  v1.0
 */
-(id)initWithIdentifier:(NSString *)identifier;
/**
 *  Start the queue. It will check the user defaults first to see if
 *  there are items still waiting to be processed, and if there are,
 *  it will push them to the current instance.
 *  Also, make sure there's a delegate object, or the queue won't start,
 *  and you'll see an error message on the console
 *
 *  @since v1.0
 */
-(void)start;
/**
 *  Add a media with a status to the current queue
 *
 *  @param media  The media object
 *  @param status The status to assign
 *  @since v1.0
 */
-(void)setMedia:(OlapicCurationMediaEntity *)media toStatus:(OlapicMediaStatus *)status;
/**
 *  Force the queue to send a request with the current items, ignoring
 *  if there's enough items to match the 'itemsToProcess' property
 *
 *  @since v1.0
 */
-(void)forceProcess;
/**
 *  Save the current status of the queue on the user defaults
 *
 *  @since v1.0
 */
-(void)saveQueue;
/**
 *  Empty the current queue and remove it from the user defaults
 *
 *  @since v1.0
 */
-(void)cleanQueue;
/**
 *  Get the current queue contents
 *
 *  @return The queue
 *  @since  v1.0
 */
-(NSArray *)getCurrentQueue;
/**
 *  Get access to the app user defaults
 *
 *  @return The reference object
 *  @since  v1.0
 */
-(NSUserDefaults *)getUserDefaults;
/**
 *  Get an instance of the object for bulk requests
 *
 *  @return A OlapicBulkRequest instance
 *  @since  v1.0
 */
-(OlapicBulkRequest *)getBulkRequest;
@end
/**
 *  The protocol to handle the queue events
 */
@protocol OlapicCurationQueueDelegate <NSObject>
@optional
/**
 *  After resolving a request, this method will be called in order to
 *  inform that the media was successfully assigned to the status
 *
 *  @param queue  The queue object
 *  @param media  The media object
 *  @param status The assigned status
 *  @since v1.0
 */

-(void)queue:(OlapicCurationQueue *)queue didAssignMedia:(OlapicCurationMediaEntity *)media toStatus:(OlapicMediaStatus *)status;
/**
 *  After resolving a request, this method will be called if one
 *  assigment failed
 *
 *  @param queue  The queue object
 *  @param error  The reason of the failure
 *  @param media  The media object
 *  @param status The status to assign
 *  @since v1.0
 */
-(void)queue:(OlapicCurationQueue *)queue didFindAnError:(NSError *)error whileAssigningMedia:(OlapicCurationMediaEntity *)media toStatus:(OlapicMediaStatus *)status;
/**
 *  This method is called if the main requests fails
 *
 *  @param queue  The queue object
 *  @param error  The reason the request failed
 *  @param media  A list with the media objects and the status
 *  @since v1.0
 */
-(void)queue:(OlapicCurationQueue *)queue didFindAnError:(NSError *)error whileSendingAListOfMedia:(NSArray *)media;
@end
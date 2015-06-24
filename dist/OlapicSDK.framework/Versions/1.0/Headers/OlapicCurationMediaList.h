//
//  OlapicCurationMediaList.h
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

#import "OlapicMediaList.h"
#import "OlapicMediaStatus.h"
#import "OlapicStreamEntity.h"
/**
 *  The different type of sorting supported by the curation lists
 */
typedef NS_ENUM(NSInteger, OlapicCurationMediaListSortingType){
    /**
     *  Ordered by date, the newer first
     */
    OlapicCurationMediaListSortingTypeRecent = 0,
    /**
     *  Ordered based on conversion
     */
    OlapicCurationMediaListSortingTypePhotorank = 2
};
/**
 *  The types of options to active the favorites filter
 */
typedef NS_ENUM(NSInteger, OlapicCurationMediaListFavoritesFilterType){
    /**
     *  Set the filter to inactive
     */
    OlapicCurationMediaListFavoritesFilterTypeNone = 0,
    /**
     *  Return all the favorites media
     */
    OlapicCurationMediaListFavoritesFilterTypeSaved = 1,
    /**
     *  Return only not favorites media
     */
    OlapicCurationMediaListFavoritesFilterTypeNotSaved = 2
};
/**
 *  The types of options to filter by default status
 */
typedef NS_ENUM(NSInteger, OlapicCurationMediaListStatusFilterType){
    /**
     *  Return all the media
     */
    OlapicCurationMediaListStatusFilterTypeAll = 0,
    /**
     *  Return all the approved media
     */
    OlapicCurationMediaListStatusFilterTypeApproved = 1,
    /**
     *  Return all the pendning media
     */
    OlapicCurationMediaListStatusFilterTypePending = 2,
    /**
     *  Return all the saved for later media
     */
    OlapicCurationMediaListStatusFilterTypeSavedForLater = 3
};
/**
 *  List all the media objects available for curation
 */
@interface OlapicCurationMediaList : OlapicMediaList
/**-----------------------------------------------------------------------------
 * @name Utils
 * -----------------------------------------------------------------------------
 */
/**
 *  Get string key for a curation sorting type
 *
 *  @param sort OlapicCurationMediaListSortingType
 *
 *  @return The string with the key
 *  @since  v1.0
 */
+(NSString *)getKeyForCurationSortingType:(OlapicCurationMediaListSortingType)sort;
/**-----------------------------------------------------------------------------
 * @name Initializer
 * -----------------------------------------------------------------------------
 */
/**
 *  Basic initialization with sorting and delegate reference
 *
 *  @param sort           The sorting type
 *  @param delegateObject The reference to the delegate object
 *
 *  @return The OlapicCurationMediaList instance
 *  @since  v1.0
 */
-(id)initWithSorting:(OlapicCurationMediaListSortingType)sort delegate:(id <OlapicMediaListDelegate>__weak)delegateObject;
/**
 *  Initialize with the sorting, the delegate reference and
 *  a specific media status
 *
 *  @param sort           The sorting type
 *  @param delegateObject The reference to the delegate object
 *  @param status         The required media status
 *
 *  @return The OlapicCurationMediaList instance
 *  @since  v1.0
 */
-(id)initWithSorting:(OlapicCurationMediaListSortingType)sort delegate:(id <OlapicMediaListDelegate>__weak)delegateObject status:(OlapicMediaStatus *)status;
/**
 *  Initialize with the sorting, the delegate reference, and
 *  a specific status or stream
 *
 *  Note: You can only use a stream or a status, not the two
 *  of them together. And in case you use them both, the method
 *  will only take the stream
 *
 *  @param sort           The sorting type
 *  @param delegateObject The reference to the delegate object
 *  @param status         The required media status
 *  @param stream         The required stream
 *
 *  @return The OlapicCurationMediaList instance
 *  @since  v1.0
 */
-(id)initWithSorting:(OlapicCurationMediaListSortingType)sort delegate:(id <OlapicMediaListDelegate>__weak)delegateObject status:(OlapicMediaStatus *)status stream:(OlapicStreamEntity *)stream;
/**
 *  Initialize with the sorting, the delegate reference, a
 *  specific status or stream and the media source (like
 *  instagram or twitter)
 *
 *  Note: You can only use a stream or a status, not the two
 *  of them together. And in case you use them both, the method
 *  will only take the stream
 *
 *  @param sort           The sorting type
 *  @param delegateObject The reference to the delegate object
 *  @param status         The required media status
 *  @param stream         The required stream
 *  @param source         The media source
 *
 *  @return The OlapicCurationMediaList instance
 *  @since  v1.0
 */
-(id)initWithSorting:(OlapicCurationMediaListSortingType)sort delegate:(id <OlapicMediaListDelegate>__weak)delegateObject status:(OlapicMediaStatus *)status stream:(OlapicStreamEntity *)stream source:(NSString *)source;
/**
 *  Initialize with the sorting, the delegate reference, a
 *  specific status or stream, the media source (like instagram
 *  or twitter) and the amount of media per page that are going
 *  going to be downloaded
 *
 *  Note: You can only use a stream or a status, not the two
 *  of them together. And in case you use them both, the method
 *  will only take the stream
 *
 *  @param sort           The sorting type
 *  @param delegateObject The reference to the delegate object
 *  @param status         The required media status
 *  @param stream         The required stream
 *  @param source         The media source
 *  @param perPage        The number of media per page
 *
 *  @return The OlapicCurationMediaList instance
 *  @since  v1.0
 */
-(id)initWithSorting:(OlapicCurationMediaListSortingType)sort delegate:(id <OlapicMediaListDelegate>__weak)delegateObject status:(OlapicMediaStatus *)status stream:(OlapicStreamEntity *)stream source:(NSString *)source mediaPerPage:(NSInteger)perPage;
/**
 *  Initialize with the sorting, the delegate reference, a
 *  specific status or stream, the media source (like instagram
 *  or twitter), the amount of media per page that are going
 *  going to be downloaded and set an offset
 *
 *  Note: You can only use a stream or a status, not the two
 *  of them together. And in case you use them both, the method
 *  will only take the stream
 *
 *  @param sort           The sorting type
 *  @param delegateObject The reference to the delegate object
 *  @param status         The required media status
 *  @param stream         The required stream
 *  @param source         The media source
 *  @param perPage        The number of media per page
 *  @param offset         The offset to change the page
 *
 *  @return The OlapicCurationMediaList instance
 *  @since  v1.0
 */
-(id)initWithSorting:(OlapicCurationMediaListSortingType)sort delegate:(id <OlapicMediaListDelegate>__weak)delegateObject status:(OlapicMediaStatus *)status stream:(OlapicStreamEntity *)stream source:(NSString *)source mediaPerPage:(NSInteger)perPage offset:(NSInteger)offset;
/**
 *  Initialize with the search text and the delegate reference.
 *
 *  @param fullTextQuery  The text search can have # @
 *  @param delegateObject The reference to the delegate object
 *
 *  @return The OlapicCurationMediaList instance
 *  @since  v1.0
 */
-(id)initWithSearch:(NSString *)fullTextQuery delegate:(id <OlapicMediaListDelegate>__weak)delegateObject;
/**
 *  Initialize with the search text, the delegate reference and
 *  the status flag.
 *
 *  @param fullTextQuery  The text search can have # @
 *  @param delegateObject The reference to the delegate object
 *  @param status         Filter by default status
 *
 *  @return The OlapicCurationMediaList instance
 *  @since  v1.0
 */
-(id)initWithSearch:(NSString *)fullTextQuery delegate:(id <OlapicMediaListDelegate>__weak)delegateObject status:(OlapicCurationMediaListStatusFilterType)status;
/**
 *  Initialize with the search text, the delegate reference and
 *  the favorited flag.
 *
 *  @param fullTextQuery  The text search can have # @
 *  @param delegateObject The reference to the delegate object
 *  @param status         Filter by default status
 *  @param favorited      If the media is favorited
 *
 *  @return The OlapicCurationMediaList instance
 *  @since  v1.0
 */
-(id)initWithSearch:(NSString *)fullTextQuery delegate:(id <OlapicMediaListDelegate>__weak)delegateObject status:(OlapicCurationMediaListStatusFilterType)status favorited:(OlapicCurationMediaListFavoritesFilterType)favorited;
/**
 *  Initialize with the search text, the delegate reference,
 *  the favorited flag and a list of sources.
 *
 *  @param fullTextQuery  The text search can have # @
 *  @param delegateObject The reference to the delegate object
 *  @param status         Filter by default status
 *  @param favorited      If the media is favorited
 *  @param sources        The media source
 *
 *  @return The OlapicCurationMediaList instance
 *  @since  v1.0
 */
-(id)initWithSearch:(NSString *)fullTextQuery delegate:(id <OlapicMediaListDelegate>__weak)delegateObject status:(OlapicCurationMediaListStatusFilterType)status favorited:(OlapicCurationMediaListFavoritesFilterType)favorited sources:(NSArray *)sources;
/**
 *  Initialize with the search text, the delegate reference,
 *  the favorited flag, a list of sources and the filter date from.
 *
 *  @param fullTextQuery  The text search can have # @
 *  @param delegateObject The reference to the delegate object
 *  @param status         Filter by default status
 *  @param favorited      If the media is favorited
 *  @param sources        The media source
 *  @param dateFrom       The filter search to a specific date
 *
 *  @return The OlapicCurationMediaList instance
 *  @since  v1.0
 */
-(id)initWithSearch:(NSString *)fullTextQuery delegate:(id <OlapicMediaListDelegate>__weak)delegateObject status:(OlapicCurationMediaListStatusFilterType)status favorited:(OlapicCurationMediaListFavoritesFilterType)favorited sources:(NSArray *)sources dateFrom:(NSString *)dateFrom;
/**
 *  Initialize with the search text, the delegate reference, 
 *  the favorited flag, a list of sources, the filter date from,
 *  and the filter to date.
 *
 *  @param fullTextQuery  The text search can have # @
 *  @param delegateObject The reference to the delegate object
 *  @param status         Filter by default status
 *  @param favorited      If the media is favorited
 *  @param sources        The media source
 *  @param dateFrom       The filter search to a specific date
 *  @param dateTo         The filter search to a specific date
 *
 *  @return The OlapicCurationMediaList instance
 *  @since  v1.0
 */
-(id)initWithSearch:(NSString *)fullTextQuery delegate:(id <OlapicMediaListDelegate>__weak)delegateObject status:(OlapicCurationMediaListStatusFilterType)status favorited:(OlapicCurationMediaListFavoritesFilterType)favorited sources:(NSArray *)sources dateFrom:(NSString *)dateFrom dateTo:(NSString *)dateTo;

@end
/*  metadata_reader.h - this file is part of MediaTomb.

    Copyright (C) 2005 Gena Batyan <bgeradz@deadlock.dhs.org>,
    Sergey Bostandzhyan <jin@deadlock.dhs.org>

    MediaTomb is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    MediaTomb is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with MediaTomb; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/// \file metadata_handler.h 
/// \brief Definition of the MetadataHandler class.
#ifndef __METADATA_HANDLER_H__
#define __METADATA_HANDLER_H__

#include "common.h"
#include "dictionary.h"
#include "cds_objects.h"
#include "io_handler.h"

// content handler Id's
#define CH_DEFAULT 0
#define CH_LIBEXIF 1

typedef enum
{
    M_TITLE = 0,
    M_ARTIST,
    M_ALBUM,
    M_DATE,
    M_GENRE,
    M_DESCRIPTION,
    M_MAX
} metadata_fields_t; 

typedef struct mt_key mt_key;
struct mt_key
{
    char *sym;
    char *upnp;
};

extern mt_key MT_KEYS[];

// res tag attributes
typedef enum
{
    R_SIZE = 0,
    R_DURATION,
    R_BITRATE,
    R_SAMPLEFREQUENCY,
    R_NRAUDIOCHANNELS,
    R_RESOLUTION,
    R_COLORDEPTH,
    R_PROTOCOLINFO,
    R_MAX
} resource_attributes_t;

typedef struct res_key res_key;
struct res_key
{   
    char *sym;
    char *upnp;
};

extern res_key RES_KEYS[];


/// \brief This class is responsible for providing access to metadata information
/// of various media. Currently only id3 is supported.
class MetadataHandler : public zmm::Object
{
public:
/// \brief Definition of the supported metadata fields.

    MetadataHandler();
       
    static void setMetadata(zmm::Ref<CdsItem> item);
    static zmm::String getMetaFieldName(metadata_fields_t field);
    static zmm::String getResAttrName(resource_attributes_t attr);

    static zmm::Ref<MetadataHandler> createHandler(int handlerType);
    
    virtual void fillMetadata(zmm::Ref<CdsItem> item) = 0;
    virtual zmm::Ref<IOHandler> serveContent(zmm::Ref<CdsItem> item, int resNum) = 0;
};

#endif // __METADATA_HANDLER_H__


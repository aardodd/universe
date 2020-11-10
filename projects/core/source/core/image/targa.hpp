#if !defined(INCLUDED_CORE_IMAGE_TARGA)
#define INCLUDED_CORE_IMAGE_TARGA

#include <core/standard/type.hpp>
#include <core/framework/visitor.hpp>

namespace universe::core {
    struct targa_header;

    struct pod_visitor : visitor<targa_header> {};

    struct targa_header : visitable<pod_visitor> {
        uint1 id_length;
        uint1 color_map_type;
        uint1 data_type_code;
        uint2 color_map_origin;
        uint2 color_map_length;
        uint1 color_map_depth;
        uint2 x_origin;
        uint2 y_origin;
        uint2 width;
        uint2 height;
        uint1 bits_per_pixel;
        uint1 image_descriptor;

        void accept(pod_visitor &_v) {
            _v.visit(*this);
        }
    };

    struct size_visitor : pod_visitor {
        uint8 struct_size = 0;

        void visit(targa_header &_data) {
            struct_size = 0;

            struct_size += sizeof(_data.id_length);
            struct_size += sizeof(_data.color_map_type);
            struct_size += sizeof(_data.data_type_code);
            struct_size += sizeof(_data.color_map_origin);
            struct_size += sizeof(_data.color_map_length);
            struct_size += sizeof(_data.color_map_depth);
            struct_size += sizeof(_data.x_origin);
            struct_size += sizeof(_data.y_origin);
            struct_size += sizeof(_data.width);
            struct_size += sizeof(_data.height);
            struct_size += sizeof(_data.bits_per_pixel);
            struct_size += sizeof(_data.image_descriptor);
        }
    };

    struct serialise_visitor : pod_visitor {
        constexpr inline serialise_visitor(byte *_data, uint8 _size) : m_data(_data), m_size(_size) {};

        void visit(targa_header &_data) {
            m_data[0] = _data.id_length;
            m_data[1] = _data.color_map_type;
            m_data[2] = _data.data_type_code;
            m_data[3] = _data.color_map_origin;
            m_data[4] = _data.color_map_origin >> 8;
            m_data[5] = _data.color_map_length;
            m_data[6] = _data.color_map_length >> 8;
            m_data[7] = _data.color_map_depth;
            m_data[8] = _data.x_origin;
            m_data[9] = _data.x_origin >> 8;
            m_data[10] = _data.y_origin;
            m_data[11] = _data.y_origin >> 8;
            m_data[12] = _data.width;
            m_data[13] = _data.width >> 8;
            m_data[14] = _data.height;
            m_data[15] = _data.height >> 8;
            m_data[16] = _data.bits_per_pixel;
            m_data[17] = _data.image_descriptor;
        }

        byte *m_data;
        uint8 m_size;
    };

    struct targa_image {
        targa_image(size _width, size _height, size _bytes_per_pixel);

        void read(const char *_filename);
        void write(const char *_filename);

        void set(uint8 _width, uint8 _height, uint4 _color);

        size m_width;
	    size m_height;
	    size m_bytes_per_pixel;
        byte *m_data;
        size m_buffer_size;
    };
}

#endif
#include <core/image/targa.hpp>
#include <core/utility/memory_copy.hpp>
#include <memory>
#include <iostream>
#include <fstream>

namespace universe::core {
    targa_image::targa_image(size _width, size _height, size _bytes_per_pixel) {
        m_width =_width;
        m_height = _height;
        m_bytes_per_pixel = _bytes_per_pixel;

        targa_header th{};
        size_visitor sv{};
        sv.visit(th);

        m_buffer_size = sv.struct_size + (m_width * m_height * m_bytes_per_pixel);
        m_data = (byte*)std::malloc(m_buffer_size);
    }

    void
    targa_image::read(const char *_filename) {
        return;
    }

    void
    targa_image::write(const char *_filename) {
        std::ofstream output{};
        output.open(_filename, std::ios::binary);
        
        targa_header th{};
        th.id_length = 0;
        th.color_map_type = 0;
        th.data_type_code = 2; // uncompressed true-color image
        th.color_map_origin = 0;
        th.color_map_length = 0;
        th.color_map_depth = 0;
        th.x_origin = 0;
        th.y_origin = 0;
        th.width = m_width;
        th.height = m_height;
        th.bits_per_pixel = m_bytes_per_pixel << 3;
        th.image_descriptor = 0x00;

        size_visitor siv{};
        siv.visit(th);

        serialise_visitor sev{m_data, siv.struct_size};
        sev.visit(th);

        output.write((char*)(m_data), m_buffer_size);
    }

    void targa_image::set(uint8 _x, uint8 _y, uint4 _color) {
        auto offset = 18 + ((_x + _y * m_width) * m_bytes_per_pixel);
        memory_copy(&m_data[offset], &_color, sizeof(_color));
    }
}
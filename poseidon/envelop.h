#ifndef ENVELOP_H
#define ENVELOP_H

namespace poseidon {
    template <typename coordinate_t>
    class Envelop {
        public:
            // 提取坐标的类型
            using x_type = typename coordinate_t::first_type;
            using y_type = typename coordinate_t::second_type;

            Envelop(const coordinate_t& southwestern, const coordinate_t& northeastern)
                : min_x_(southwestern.x()), min_y_(southwestern.y()),
                  max_x_(northeastern.x()), max_y_(northeastern.y()) {}
            
            x_type min_x() const { return min_x_; }
            y_type min_y() const { return min_y_; }
            x_type max_x() const { return max_x_; }
            y_type max_y() const { return max_y_; }

            x_type width() const { return max_x_ - min_x_; }
            y_type height() const { return max_y_ - min_y_; }
        private:
            x_type min_x_;
            y_type min_y_;
            x_type max_x_;
            y_type max_y_;
    };
}


#endif // ENVELOP_H
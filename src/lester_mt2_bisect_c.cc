#include "lester_mt2_bisect.h"
#include "lester_mt2_bisect_c.h"

extern "C" {
    double asymm_mt2_lester_bisect(double m_vis1, double px_vis1, double py_vis1,
                                   double m_vis2, double px_vis2, double py_vis2,
                                   double px_miss, double py_miss,
                                   double m_invis1, double m_invis2) {
        asymm_mt2_lester_bisect::disableCopyrightMessage();
        return asymm_mt2_lester_bisect::get_mT2(m_vis1, px_vis1, py_vis1,
                                                m_vis2, px_vis2, py_vis2,
                                                px_miss, py_miss,
                                                m_invis1, m_invis2);
    }
}

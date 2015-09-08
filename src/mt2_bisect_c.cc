#include "mt2_bisect.h"
#include "mt2_bisect_c.h"

extern "C" {
    double symm_mt2_chenghan_bisect(double m_vis1, double px_vis1, double py_vis1,
                                    double m_vis2, double px_vis2, double py_vis2,
                                    double px_miss, double py_miss,
                                    double m_invis) {
        double pa[3] = {m_vis1, px_vis1, py_vis1};
        double pb[3] = {m_vis2, px_vis2, py_vis2};
        double pmiss[3] = {0.0, px_miss, py_miss};
        mt2_bisect::mt2 mt2_event;
        mt2_event.set_momenta(pa, pb, pmiss);
        mt2_event.set_mn(m_invis);
        return mt2_event.get_mt2();
    }
}

#ifndef SRC_LESTER_MT2_BISECT_C_H_
#define SRC_LESTER_MT2_BISECT_C_H_

#ifdef __cplusplus
extern "C" {
#endif

    double asymm_mt2_bisect(double m_vis1, double px_vis1, double py_vis1,
                            double m_vis2, double px_vis2, double py_vis2,
                            double px_miss, double py_miss,
                            double m_invis1, double m_invis2);

#ifdef __cplusplus
}
#endif

#endif  // SRC_LESTER_MT2_BISECT_C_H_

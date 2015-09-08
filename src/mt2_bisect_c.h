#ifndef SRC_MT2_BISECT_C_H_
#define SRC_MT2_BISECT_C_H_

#ifdef __cplusplus
extern "C" {
#endif

    double symm_mt2_chenghan_bisect(double m_vis1, double px_vis1, double py_vis1,
                                    double m_vis2, double px_vis2, double py_vis2,
                                    double px_miss, double py_miss,
                                    double m_invis);

#ifdef __cplusplus
}
#endif

#endif  // SRC_MT2_BISECT_C_H_

/*
 *  Copyright (c) 2015, 2017 Chan Beom Park <cbpark@gmail.com>
 *
 *  This file is part of mt2-cwrapper, which is released under the GNU General
 *  Public License. See file LICENSE in the top directory of this project or
 *  go to <http://www.gnu.org/licenses/> for full license details.
 */

#include "lester_mt2_bisect_c.h"
#include "lester_mt2_bisect.h"

extern "C" {
double asymm_mt2_lester_bisect(double m_vis1, double px_vis1, double py_vis1,
                               double m_vis2, double px_vis2, double py_vis2,
                               double px_miss, double py_miss, double m_invis1,
                               double m_invis2) {
    asymm_mt2_lester_bisect::disableCopyrightMessage();
    return asymm_mt2_lester_bisect::get_mT2(m_vis1, px_vis1, py_vis1, m_vis2,
                                            px_vis2, py_vis2, px_miss, py_miss,
                                            m_invis1, m_invis2);
}
}

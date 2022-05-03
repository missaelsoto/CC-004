/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** Command: kcg662.exe -config C:/Users/missael/Documents/CINVESTAV/embedded critical software/Project/CC-003/System__SystemSimul_KCG66/config.txt
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */

#include "kcg_types.h"

#ifdef kcg_use_array_float64_5
kcg_bool kcg_comp_array_float64_5(
  array_float64_5 *kcg_c1,
  array_float64_5 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 5; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_array_float64_5 */

/* $********** SCADE Suite KCG 32-bit 6.6.2 (build i4) **********
** kcg_types.c
** Generation date: 2022-04-26T09:36:58
*************************************************************$ */


/**************************************************************************************/
/**                                                                                \n**/
/**        t u r n o v e r _ m o n t h l y _ t r e e . c                           \n**/
/**                                                                                \n**/
/**     C implementation of LPJmL                                                  \n**/
/**                                                                                \n**/
/** (C) Potsdam Institute for Climate Impact Research (PIK), see COPYRIGHT file    \n**/
/** authors, and contributors see AUTHORS file                                     \n**/
/** This file is part of LPJmL and licensed under GNU AGPL Version 3               \n**/
/** or later. See LICENSE file or go to http://www.gnu.org/licenses/               \n**/
/** Contact: https://gitlab.pik-potsdam.de/lpjml                                   \n**/
/**                                                                                \n**/
/**************************************************************************************/

#include "lpj.h"
#include "tree.h"

void turnover_monthly_tree(Litter *litter,Pft *pft)
{
  Pfttree *tree;
  Pfttreepar *treepar;  
  treepar=pft->par->data;
  tree=pft->data;
  tree->turn.root+=tree->ind.root*treepar->turnover.root/NMONTH;
  tree->turn_litt.root+=tree->ind.root*treepar->turnover.root/NMONTH*pft->nind;
  litter->bg[pft->litter]+=tree->ind.root*treepar->turnover.root/NMONTH*pft->nind;
} /* of 'turnover_monthly_tree' */
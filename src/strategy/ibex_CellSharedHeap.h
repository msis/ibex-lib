//============================================================================
//                                  I B E X                                   
// File        : ibex_CellHeap.h
// Author      : Jordan Ninin
// Copyright   : Ecole des Mines de Nantes (France)
// License     : See the LICENSE file
// Created     : May 12, 2012
// Last Update : May 12, 2012
//============================================================================

#ifndef __IBEX_CELL_SHARED_HEAP_H__
#define __IBEX_CELL_SHARED_HEAP_H__

#include "ibex_CellBuffer.h"
#include "ibex_Cell.h"
#include "ibex_Heap.h"
#include "ibex_Interval.h"
#include "ibex_OptimData.h"
#include "ibex_Exception.h"

namespace ibex {

// -----------------------------------------------------------------------------------------------------------------------------------

/**
 * \ingroup strategy
 *
 * \brief Cell Heap based on lower bound criterion
 */
class CellHeapVarLB: public CellHeap  {
public:

	CellHeapVarLB(int goal_var, int ind_crit=0) ;


private:
	/** Index of the objective variable. */
	const int goal_var;

	/** The "cost" of a element. */
	double cost(const Cell& c) const;

};
// -----------------------------------------------------------------------------------------------------------------------------------

/**
 * \ingroup strategy
 *
 * \brief Cell Heap based on upper bound criterion
 */
class CellHeapVarUB: public CellHeap  {
public:

	CellHeapVarUB(int ind_var, int ind_crit=0) ;


private:
	/** Index of the objective variable. */
	const int goal_var;

	/** The "cost" of a element. */
	double cost(const Cell& c) const;

};
// -----------------------------------------------------------------------------------------------------------------------------------

/**
 * \ingroup strategy
 *
 * \brief Cost-based Cell Heap
 */
class CellHeapC3: public CellHeap {
public:

	CellHeapC3(int ind_crit=0, double lb= NEG_INFINITY) ;

	/**
	 * \brief Contracts the heap.
	 *
	 * Removes (and deletes) from the heap all the elements
	 * with a cost greater than \a lb.
	 */
	inline void contractHeap(double lb) { loup = lb; Heap<Cell>::contractHeap(lb);}

private:

	/** the lower upper bound. */
	double loup;

	CellHeapC3* init_copy();

	/** The "cost" of a element. */
	double cost(const Cell& c) const;

};
// -----------------------------------------------------------------------------------------------------------------------------------


class CellHeapC5: public CellHeap {
public:

	CellHeapC5(int ind_crit=0, double lb= NEG_INFINITY) ;

	/**
	 * \brief Contracts the heap.
	 *
	 * Removes (and deletes) from the heap all the elements
	 * with a cost greater than \a lb.
	 */
	inline void contractHeap(double lb) { loup = lb; Heap<Cell>::contractHeap(lb);}


private:

	/** the lower upper bound. */
	double loup;

	CellHeapC5* init_copy();

	/** The "cost" of a element. */
	double cost(const Cell& c) const;
};
// -----------------------------------------------------------------------------------------------------------------------------------

class CellHeapC7: public CellHeap {
public:


	CellHeapC7(int ind_var, int ind_crit=0, double lb=NEG_INFINITY) ;

	/**
	 * \brief Contracts the heap.
	 *
	 * Removes (and deletes) from the heap all the elements
	 * with a cost greater than \a lb.
	 */
	inline void contractHeap(double lb) { loup = lb; Heap<Cell>::contractHeap(lb);}


private:
	/** Index of the objective variable. */
	const int goal_var;

	/** the lower upper bound. */
	double loup;

	CellHeapC7* init_copy();

	/** The "cost" of a element. */
	double cost(const Cell& c) const;
};

// -----------------------------------------------------------------------------------------------------------------------------------

class CellHeapPU: public CellHeap {
public:
	CellHeapPU(int ind_crit=0) ;

private:

	/** The "cost" of a element. */
	double cost(const Cell& c) const;

};


class CellHeapPFlb: public CellHeap {
public:
	CellHeapPFlb(int ind_crit=0) ;

private:
	/** The "cost" of a element. */
	double cost(const Cell& c) const;

};

// -----------------------------------------------------------------------------------------------------------------------------------


class CellHeapPFub: public CellHeap {
public:
	CellHeapPFub(int ind_crit=0) ;

private:
	/** The "cost" of a element. */
	double cost(const Cell& c) const;

};

} // end namespace ibex
#endif // __IBEX_CELL_SHARED_HEAP_H__

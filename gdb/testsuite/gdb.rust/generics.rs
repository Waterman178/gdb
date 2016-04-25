// Copyright (C) 2016 Free Software Foundation, Inc.

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#![allow(dead_code)]
#![allow(unused_variables)]
#![allow(unused_assignments)]


struct GenericStruct<T> {
    one: T,
    two: T
}

pub fn identity<T>(x: T) -> T { x }

pub fn tupleize<T, U>(x: T, y: U) -> (U,T) { (y, x) }

pub fn main() {
    let a = identity(23u32);
    let b = identity(23.0f64);

    let c = tupleize(b,a);
    let d = identity::<u32>(7);

    let e = GenericStruct{one: 7, two: 9};
    let f = GenericStruct::<u8>{one: 7, two: 9};

    let g = tupleize(d, e);
    let h = tupleize(d, f);

    ()                          // set breakpoint here
}

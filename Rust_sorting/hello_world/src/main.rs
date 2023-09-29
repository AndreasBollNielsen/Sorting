use rand::prelude::*;
use std::time::Instant;

fn main() {
    // initialize random generator
    let mut random = rand::thread_rng();

    //generate array
    let mut arr = [0;100000];

    for i in 0..10 {
        arr[i] = random.gen_range(1..100000);
    }
    let mut dynarray = arr.to_vec();
   
   //start clock
   let start_time = Instant::now();
    selection_sort(&mut dynarray);
    let end_time = Instant::now();

    let timespend = end_time.duration_since(start_time);

    println!("{:?}",dynarray);
    println!("time taken in {} ms", timespend.as_secs());
}

fn selection_sort( source_arr: &mut Vec<i32>) {
    
    let size = source_arr.len();

    for i in 0..size {
        let mut min_index = i;

        for n in (i + 1)..size {
            if source_arr[n] < source_arr[min_index] {
                min_index = n;
            }
        }

        if min_index != i {
            source_arr.swap(i, min_index);
        }
    }
}

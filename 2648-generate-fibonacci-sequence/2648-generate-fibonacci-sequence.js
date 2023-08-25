/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let a = 0;
    let b =1;

    for(let i =1 ; i<=50 ; i++){
        let c = a+b ;
        yield a;

        a =b ;
        b =c;

    }
};


/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
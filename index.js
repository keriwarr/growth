import R from 'ramda';

const f = R.compose(
  a => a + 3,
  b => b * 4,
);

console.log(f(10));

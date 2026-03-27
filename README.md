*This project has been created as part of the 42 curriculum by rwegat.*

## Description

This is a rewrite of my original solution using the "Turk Sort" or "Case Sort".
Elements are presorted by pushing them to stack B in chunks, then moved back to stack A
in the cheapest order to reach the final sorted state.
This is an algo tailored to the subject requirements by minimizing the number of operations 
at the cost of extra comparisons.

## Instructions

Build and run from the project root:

```sh
make
./push_swap 3 2 1
```

Easy Testing:

```sh
python3 - <<'PY' | tee input.txt | xargs ./push_swap > output.txt
import random
print(' '.join(map(str, random.sample(range(1,101), 100))))
PY
```

```sh
python3 - <<'PY' | tee input.txt | xargs ./push_swap > output.txt
import random
print(' '.join(map(str, random.sample(range(1,501), 500))))
PY
```

## Resources

https://youtu.be/OaG81sDEpVk?si=Xq9uwBYAskkVuCZH

## Additional

https://github.com/rmwegat
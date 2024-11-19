#!bin/bash/
sudo ./build/X86/gem5.opt -d ./outputs/433.milc/lrustats/ ./configs/deprecated/example/se.py -n 1 --sys-clock=3GHz --mem-type=DDR3_1600_8x8 --mem-size=4GB --caches --l1i_size=32kB --l1i_assoc=4 --l1d_size=32kB --l1d_assoc=4 --l2cache --l2_size=256kB --l2_assoc=16 --cpu-type=O3CPU --bp-type=TAGE_SC_L_64KB --l2-hwp-type=BOPPrefetcher --cpu-clock=3GHz -W 50000000 -I 50000000 -c ./specs/433.milc/exe/milc_base.gcc43-64bit --input ./specs/433.milc/data/test/input/su3imp.in
sudo ./build/X86/gem5.opt -d ./outputs/456.hmmer/lrustats ./configs/deprecated/example/se.py -n 1 --sys-clock=3GHz --mem-type=DDR3_1600_8x8 --mem-size=4GB --caches --l1i_size=32kB --l1i_assoc=4 --l1d_size=32kB --l1d_assoc=4 --l2cache --l2_size=256kB --l2_assoc=16 --cpu-type=O3CPU --bp-type=TAGE_SC_L_64KB --l2-hwp-type=BOPPrefetcher --cpu-clock=3GHz -W 50000000 -I 50000000 -c ./specs/456.hmmer/exe/hmmer_base.gcc43-64bit -o ./specs/456.hmmer/data/test/input/bombesin.hmm
sudo ./build/X86/gem5.opt -d ./outputs/998.specrand/lrustats ./configs/deprecated/example/se.py -n 1 --sys-clock=3GHz --mem-type=DDR3_1600_8x8 --mem-size=4GB --caches --l1i_size=32kB --l1i_assoc=4 --l1d_size=32kB --l1d_assoc=4 --l2cache --l2_size=256kB --l2_assoc=16 --cpu-type=O3CPU --bp-type=TAGE_SC_L_64KB --l2-hwp-type=BOPPrefetcher --cpu-clock=3GHz -W 50000000 -I 50000000 -c ./specs/998.specrand/exe/specrand_base.gcc43-64bit -o "324234 24232"

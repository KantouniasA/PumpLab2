load m1.txt
samplingFrequency   = 0.004;
singalLength        = length(m1);
time                = 0:samplingFrequency:samplingFrequency*(singalLength-1);

%% FFT analysis
m1FFT               = fft(m1); 

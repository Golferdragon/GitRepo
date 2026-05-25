#![no_std]
#![no_main]

use cortex_m_rt::entry;
use panic_halt as _; // halts on panic
use stm32f3xx_hal::{pac, prelude::*};

#[entry]
fn main() -> ! {
    let dp = pac::Peripherals::take().unwrap();

    let mut rcc = dp.RCC.constrain();
    let mut flash = dp.FLASH.constrain();
    let clocks = rcc.cfgr.freeze(&mut flash.acr);

    let mut gpioe = dp.GPIOE.split(&mut rcc.ahb);
    let mut led = gpioe.pe9.into_push_pull_output(&mut gpioe.moder, &mut gpioe.otyper);

    loop {
        led.toggle().unwrap();
        cortex_m::asm::delay(8_000_000); // adjust for blink rate
    }
}

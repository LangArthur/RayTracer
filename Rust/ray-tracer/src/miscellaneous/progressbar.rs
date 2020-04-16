use std::sync::mpsc;
use std::thread;

pub struct ProgressBar {

    handler:    thread::JoinHandle<()>,
    sender:     mpsc::Sender<f64>,
}

impl ProgressBar {

    pub fn new(max_value: f64, number_of_lines: u32) -> ProgressBar {

        let (tx, rx): (mpsc::Sender<f64>, mpsc::Receiver<f64>) = mpsc::channel();

        ProgressBar {
            handler: thread::spawn(move || {

                let loading: [char; 4] = ['-', '\\', '|', '/'];
                let mut i = 0;
                let max = max_value;
                let mut progress = 0.0;
                let mut percentage = 0.0;
                // let mut lines = number_of_lines;
                // let mut bars = 0;

                for received in rx {

                    progress += received;
                    percentage = progress / max * 100.0;

                    print!("\r[{}] progress: {}%", loading[i], percentage as u32);
                    i = if i < 3 { i + 1 } else { 0 };
                }
            }),
            sender: tx,
        }
    }

    pub fn inc(&mut self, n: f64) {
        self.sender.send(n).unwrap();
    }
}
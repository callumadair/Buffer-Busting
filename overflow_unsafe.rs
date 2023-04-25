unsafe fn overflow(input: &[u8]) {
      let mut buf: [u8; 12] = [0; 12];
      std::ptr::copy_nonoverlapping(input.as_ptr(), buf.as_mut_ptr(), 12);
  }

  fn main() {
      let input = b"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
      unsafe { overflow(input); };
  }

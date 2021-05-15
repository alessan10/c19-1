import { Component, OnInit } from '@angular/core';
import { FormBuilder, Validators } from '@angular/forms';

@Component({
  selector: 'app-patient-insert',
  templateUrl: './patient-insert.component.html',
  styleUrls: ['./patient-insert.component.scss'],
})
export class PatientInsertComponent implements OnInit {

  get name() { return this.insertionForm.get('name'); }

  get surname() { return this.insertionForm.get('surname'); }

  get age() { return this.insertionForm.get('age'); }

  get covid(){ return this.insertionForm.get('covid') }

  get country() { return this.insertionForm.get('country'); }

  constructor(private fb: FormBuilder) {}

  insertionForm = this.fb.group({
    name: ['', [Validators.required, Validators.minLength(2)]],
    surname: ['', [Validators.required, Validators.minLength(2)]],
    age: [''],
    covid: ['', Validators.required],
    country: [''],
    date: [''],
  });

  // insertionForm = new FormGroup({
  //   name: new FormControl(''),
  //   surname: new FormControl(''),
  //   age: new FormControl(''),
  //   covid: new FormControl(''),
  //   country: new FormControl(''),
  //   date: new FormControl('')
  // });

  ngOnInit(): void {}
}
